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
int _,n;
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d",&n);
        int sum=0;
        for (int i=1;i<=n;i++){
            int x; scanf("%d",&x);
            sum+=x;
        }
        if ((sum-n)&1) puts("errorgorn"); else puts("maomao90");
    }
}