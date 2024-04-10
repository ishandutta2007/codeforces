#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
string str;
int q;
struct seg{
    int s,e,m;
    bool exist=false;
    seg *l,*r;
    seg(int _s,int _e){
        s=_s,e=_e,m=(s+e)>>1;
        if (s!=e){
            l=new seg(s,m);
            r=new seg(m+1,e);
        }
    }
    void update(int i, bool j){
        if (s==e) exist=j;
        else{
            if (i<=m) l->update(i,j);
            else r->update(i,j);
            exist=l->exist||r->exist;
        }
    }
    bool query(int i,int j){
        if (s==i && j==e) return exist;
        else if (j<=m) return l->query(i,j);
        else if (m<i) return r->query(i,j);
        else return l->query(i,m)||r->query(m+1,j);
    }
};
seg* segs[30];
int main(){
    cin>>str;
    for (int x=0;x<30;x++){
        segs[x]=new seg(1,str.size());
    }
    str="$"+str;
    for (int x=1;x<str.size();x++){
        segs[str[x]-'a']->update(x,true);
    }
    scanf("%d",&q);
    int a,b;
    char c;
    int ans;
    while (q--){
        scanf("%d",&a);
        if (a==1){
            scanf("%d %c",&a,&c);
            segs[str[a]-'a']->update(a,false);
            segs[c-'a']->update(a,true);
            str[a]=c;
        }
        else{
            scanf("%d%d",&a,&b);
            ans=0;
            for (int x=0;x<26;x++){
                ans+=segs[x]->query(a,b);
            }
            printf("%d\n",ans);
        }
    }
}