#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll t, x[99], n;
string s = "codeforces";
ll cek()
{
    ll K = 1;
    for(ll i = 0; i < 10; i++)
        K *= (x[i] + 1);
    return K;
}
void cetak()
{
    for(ll i = 0; i < 10; i++)
        for(ll j = 0; j <= x[i]; j++)
            cout << s[i];
    cout << "\n";
    exit(0);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> n;
    if(n == 1)
        cetak();
    for(ll i = 0; i < 100000; i++)
    {
        x[i % 10]++;
        if(cek() >= n)
            cetak();
    }
}