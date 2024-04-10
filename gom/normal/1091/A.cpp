#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int N=8e5+5;
int y,b,r;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>y>>b>>r;
    for(int i=y;i>=1;i--){
        if(b>=i+1&&r>=i+2){
            cout<<3*i+3;
            return 0;
        }
    }
    return 0;
}