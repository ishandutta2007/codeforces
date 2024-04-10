#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define index Index
#define MXN 10000
void solve(){
    int n;
    scanf("%d",&n);
    int a[100005];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    if(n%2==1){
        printf("No\n");
    }else{
        sort(a,a+n);
        vector<int> v1,v2;
        int l=0,r=n/2;
        for(int i = 0;i<n/2;i++){
            v1.pb(a[l]);
            v1.pb(a[r]);
            v2.pb(a[r]);
            v2.pb(a[l]);
            l++;
            r++;
        }
        for(int t=0;t<2;t++){
            int ok=1;
            for(int i = 0;i<v1.size();i++){
                if(v1[i]>v1[(i+n-1)%n]&&v1[i]>v1[(i+1)%n]){

                }
                else if(v1[i]<v1[(i+n-1)%n]&&v1[i]<v1[(i+1)%n]){
                }
                else{
                    ok=0;
                }
            }
            if(ok){
                printf("Yes\n");
                for(auto it:v1)printf("%d ",it);
                printf("\n");
                return;
            }
            swap(v1,v2);
        }
        printf("No\n");
    }
}
int main(){
   // srand(time(NULL));
    int t=1;;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}