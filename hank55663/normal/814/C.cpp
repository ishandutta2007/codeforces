#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
#define N 200005
#define rank Rank
#define index Index
int main(){
    int n;
    scanf("%d",&n);
    char c[1505];
    scanf("%s",c);
    vector<int> v[26];
    int q;
    scanf("%d",&q);
    while(q--){
        int m;
        char cc;
        scanf("%d %c",&m,&cc);
        int r=0;
        for(;r<n;r++){
            if(c[r]==cc);
            else{
                if(m==0)
                break;
                m--;
            }
        }
        int ans=0;
        for(int i = 0;i<n;i++){
            ans=max(ans,r-i);
//printf("%d\n",r-i);
            if(c[i]!=cc)m++;
            while(r<n){
                if(c[r]==cc);
                else{
                    if(m==0)
                    break;
                    m--;
                }
                r++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}