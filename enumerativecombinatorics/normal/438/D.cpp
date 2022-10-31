#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
int c[110000];
int SQ=200;
long long bag[700];
set<pair<int,int> >S[700];
pair<int,int>tmp[1000];
long long query(int a,int b){
    long long ret=0;
    int L=a/SQ+1;
    int R=b/SQ;
    for(int i=L;i<R;i++){
        ret+=bag[i];
    }
    if(L>=R){
        for(int i=a;i<=b;i++)ret+=c[i];
    }else{
        for(int i=a;i<L*SQ;i++)ret+=c[i];
        for(int i=R*SQ;i<=b;i++)ret+=c[i];
    }
    return ret;
}
void update(int a,int b){
    S[a/SQ].erase(make_pair(c[a],a));
    bag[a/SQ]-=c[a];
    c[a]=b;
    bag[a/SQ]+=b;
    S[a/SQ].insert(make_pair(c[a],a));
}
void updmod(int a,int b,int f){
    int L=a/SQ+1;
    int R=b/SQ;
    for(int i=L;i<R;i++){
        int n=0;
        for(set<pair<int,int> >::iterator it=S[i].lower_bound(make_pair(f,0));it!=S[i].end();it++){
            tmp[n++]=(*it);
        }
        for(int j=0;j<n;j++)update(tmp[j].second,tmp[j].first%f);
    }
    if(L>=R){
        for(int i=a;i<=b;i++)if(c[i]>=f)update(i,c[i]%f);
    }else{
        for(int i=a;i<L*SQ;i++)if(c[i]>=f)update(i,c[i]%f);
        for(int i=R*SQ;i<=b;i++)if(c[i]>=f)update(i,c[i]%f);
    }
}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=0;i<a;i++)scanf("%d",c+i);
    for(int i=0;i<a;i++){
        S[i/SQ].insert(make_pair(c[i],i));
        bag[i/SQ]+=c[i];
    }
    while(b--){
        int p;
        scanf("%d",&p);
        if(p==1){
            int l,r;scanf("%d%d",&l,&r);
            l--;r--;
            printf("%I64d\n",query(l,r));
        }else if(p==2){
            int l,r,x;scanf("%d%d%d",&l,&r,&x);
            l--;r--;
            updmod(l,r,x);
        }else{
            int k,x;
            scanf("%d%d",&k,&x);
            k--;
            update(k,x);
        }
    }
}