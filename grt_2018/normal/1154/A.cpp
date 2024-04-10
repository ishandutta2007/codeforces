#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back
#define DET(a,b,c) (LL(b.x-a.x)*LL((c.y-a.y))-LL((c.x-a.x))*LL((b.y-a.y)))

int a[4];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0; i<4;i++) cin>>a[i];
    sort(a,a+4);
    int b = a[3] - a[2];
    int c = a[1] - b;
    cout<<b<<" "<<c<<" "<<a[3]-b-c;

}