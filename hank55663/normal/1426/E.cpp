#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define pll pair<LL,LL>
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    int a[3],b[3];
    for(int i = 0;i<3;i++)scanf("%d",&a[i]);
    for(int i = 0;i<3;i++)scanf("%d",&b[i]);
    int Max=0,Min=0;
    Max+=min(a[0],b[1]);
    Max+=min(a[1],b[2]);
    Max+=min(a[2],b[0]);
    Min+=max(a[0]-b[0]-b[2],0);
    Min+=max(a[1]-b[0]-b[1],0);
    Min+=max(a[2]-b[1]-b[2],0);
    printf("%d %d\n",Min,Max);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
       // printf("Case #%d: ",T++);
        solve();
    }
}