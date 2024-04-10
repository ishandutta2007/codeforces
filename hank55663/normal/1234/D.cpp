#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 1500
int S[26][100005];
void add(int x,int k,int *s){
    for(int i = x;i<100005;i+=i&-i){
        s[i]+=k;
    }
}
int query(int x,int *s){
    int res=0;
    for(int i =x;i>0;i-=i&-i){
        res+=s[i];
    }
    return res;
}
int main(){
    char c[100005];
    scanf("%s",c+1);
    for(int i = 1;c[i]!=0;i++){
        add(i,1,S[c[i]-'a']);
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int p;
            char cc;
            scanf("%d %c",&p,&cc);
            add(p,-1,S[c[p]-'a']);
            c[p]=cc;
            add(p,1,S[c[p]-'a']);
        }
        else{
            int l,r;
            scanf("%d %d",&l,&r);
            int ans=0;
            for(int i = 0;i<26;i++){
                if(query(r,S[i])-query(l-1,S[i])){
                    ans++;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}