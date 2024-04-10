#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int value[300005];
    fill(value,value+n+5,0);
    LL cnt=0;
    for(int i = 1;i<=n;i++){
        for(int j = i*2;j<=n;j+=i){
            value[j]++;
        }
        cnt+=value[i];
        if(cnt>=k)
        {
            printf("Yes\n");
            int Max=i;
            set<int> s;
            for(int j=1;j<=i;j++)
            s.insert(j);
            vector<pii> v;
            for(int j =i/2+1;j<=i;j++){
                v.pb(mp(value[j],j));
            }
            sort(v.begin(),v.end());
            reverse(v.begin(),v.end());
            for(auto it:v){
                if(cnt-it.x>=k){
                    cnt-=it.x;
                    s.erase(it.y);
                }
            }
            assert(cnt==k);
            printf("%d\n",s.size());
            for(auto it:s)
            printf("%d ",it);
            printf("\n");
            return 0;

        }
    }
    printf("No\n");

}