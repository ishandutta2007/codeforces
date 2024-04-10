#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back

int n;
int x,s1,s2;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n;i++) {
        cin>>x; s1+=x;
    }
    for(int i=0; i<n;i++) {
        cin>>x; s2+=x;
    }
    if(s1>=s2) cout<<"Yes";
    else cout<<"No";
}