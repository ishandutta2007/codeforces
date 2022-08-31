#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int maxn=1e6+10;
const int M=998244353;
int _,n,x;
int main(){
    cin >> _;
    while (_--){
        cin >> n; for (int i=1;i<=n;i++) cin >> x;
        cout << n*3 << endl;
        for (int i=1;i<=n;i+=2){
            printf("%d %d %d\n",1,i,i+1);
            printf("%d %d %d\n",2,i,i+1);
            printf("%d %d %d\n",1,i,i+1);
            printf("%d %d %d\n",1,i,i+1);
            printf("%d %d %d\n",2,i,i+1);
            printf("%d %d %d\n",1,i,i+1);
        }
    }
    return 0;
}