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
#define ld long double
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int tmp=n;
        map<int,int> m;
        int cnt=0;
        for(int i =2;i*i<=n;i++){
            while(n%i==0){
                m[i]++;
                n/=i;
                cnt++;
            }
        }
        if(n!=1)m[n]++,cnt++;
        if(m.size()==1){
            if(cnt>=6){
                printf("YES\n");
                int x=m.begin()->x;
                printf("%d %d %d\n",x,x*x,tmp/x/x/x);
            }
            else{
                printf("NO\n");
            }
        }
        else if(m.size()==2){
            if(cnt>3){
                printf("YES\n");
                vector<int> v;
                for(auto it:m)v.pb(it.x);
                //printf("YES\n");
                printf("%d %d %d\n",v[0],v[1],tmp/v[0]/v[1]);
            }
            else{
                printf("NO\n");
            }
        }
        else{
            vector<int> v;
            for(auto it:m)v.pb(it.x);
            printf("YES\n");
            printf("%d %d %d\n",v[0],v[1],tmp/v[0]/v[1]);
        }
    }
}