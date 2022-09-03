#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define pii pair<int,int>
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int n;
        scanf("%d",&n);
        vector<int> v;
        for(int i = 0;i<n;i++){
            int x;
            scanf("%d",&x);
            v.pb(x);
        }
        sort(v.begin(),v.end());
        int ok=0;
        for(int i = 0;i<n-1;i++){
            if(v[i+1]-v[i]==1)ok=1;
        }
        printf("%d\n",1+ok);
    }
}