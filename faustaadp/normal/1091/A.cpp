#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll A,B,C,D;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>A>>B>>C;
    A+=2;
    B++;
    D=min(A,min(B,C));
    D*=3;
    D-=3;
    cout<<D<<"\n";
}