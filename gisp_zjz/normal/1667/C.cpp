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
int n,x,m;
int main(){
    scanf("%d",&n);
    if (n==1){puts("1");puts("1 1");return 0;}
    x=(n+1)/3;
    m=x*2-1;
    printf("%d\n",n-x);
    for (int i=0;i<m;i++) printf("%d %d\n",i+1,i*2%m+1);
    for (int i=m;i<n-x;i++) printf("%d %d\n",i+1,i+1);
    return 0;
}