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
    int n;
    scanf("%d",&n);
    char c[200005];
    vector<char> ans;
    scanf("%s",c);
    for(int i = 0;c[i]!=0;i++){
        if(ans.size()&1){
            if(ans.back()!=c[i]){
                ans.pb(c[i]);
            }
        }
        else{
            ans.pb(c[i]);
        }
    }
    if(ans.size()&1)ans.pop_back();
    printf("%d\n",n-ans.size());
    for(auto it:ans)
    printf("%c",it);
    printf("\n");
}