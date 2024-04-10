#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const int maxn=3e5+7;
int n,m,o;

int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&m);
        if (m%2==0) printf("%d\n",m/2);
        else {
            if (o) m++; else m--;
            o^=1;
            printf("%d\n",m/2);
        }
    }
}