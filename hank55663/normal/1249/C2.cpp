#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define pii pair<int,int>
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
LL pow3[50];
int main(){
    pow3[0]=1;
    for(int i=1;i<50;i++)
        pow3[i]=pow3[i-1]*3;
    int q;
    scanf("%d",&q);
    while(q--){
        LL x;
        scanf("%lld",&x);
        vector<int> v;
        while(x){
            v.pb(x%3);
            x/=3;
        }
        v.pb(0);
        for(int i = v.size()-1;i>=0;i--){
            if(v[i]==2){
                v[i+1]++;
                v[i]=0;
                for(int j =i;j>=0;j--)
                    v[j]=0;
                break;
            }
        }
        for(int i = 0;i<v.size();i++){
            if(v[i]>=2){
                v[i]=0;
                v[i+1]++;
            }
        }
        LL ans=0;
        for(int i = 0;i<v.size();i++)
            ans+=pow3[i]*v[i];
        printf("%lld\n",ans);
    } 

}