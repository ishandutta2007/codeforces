#include<bits/stdc++.h>
#define F first
#define S second
#define maxn 1234

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
double l,r,p,d,mid;
int n,a[maxn],b[maxn];

bool check(double x){
    p=x+d;
    for (int i=0;i<n;i++){
        p-=p/a[i]; if (p<d) return false;
        p-=p/b[i]; if (p<d) return false;
    }
    return true;
}

int main(){
    cin >> n >> d;
    for (int i=0;i<n;i++) cin >> a[i]; cin >> b[n-1];
    for (int i=0;i<n-1;i++) cin >> b[i];
    l=0; r=1e9;
    if (!check(2e9)) puts("-1");
    else {
        for (int i=0;i<200;i++){
            mid=(l+r)/2;
            if (check(mid)) r=mid; else l=mid;
        }
        printf("%.7f\n",mid);
    }
}