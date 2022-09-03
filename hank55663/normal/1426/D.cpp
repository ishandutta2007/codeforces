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
    int a[200005];
    set<LL> s;
    int ans=0;
    LL sum=0;
    s.insert(sum);
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
        if(s.find(sum)==s.end())s.insert(sum);
        else{
            ans++;
            sum=0;
            s.clear();
            s.insert(sum);
            sum+=a[i];
            s.insert(sum);
        }
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
       // printf("Case #%d: ",T++);
        solve();
    }
}