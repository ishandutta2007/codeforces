#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string s0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string s1 = "What are you doing while sending \"";
string s2 = "\"? Are you busy? Will you send \"";
string s3 = "\"?";

ll flen[55];

char findChar(int n, ll k){
    if(n == 0){
        if(k <= s0.size())return s0[k-1];
        return '.';
    }
    if(n > 53){
        if(k <= s1.size()){
            return s1[k-1];
        }
        k -= s1.size();
        return findChar(n - 1, k);
    }
    if(k <= s1.size())return s1[k-1];
    k -= s1.size();
    if(flen[n-1] >= k)return findChar(n - 1, k);
    k -= flen[n-1];
    if(k <= s2.size())return s2[k-1];
    k -= s2.size();
    if(flen[n-1] >= k)return findChar(n - 1, k);
    k -= flen[n-1];
    if(k <= s3.size())return s3[k-1];
    return '.';
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    flen[0] = s0.size();
    for(int i = 1; i < 55; i++){
        flen[i] = 2*flen[i-1] + s1.size() + s2.size() + s3.size();
    }
    ll k;
    int q, n;
    cin>>q;
    while(q--){
        cin>>n>>k;
        cout<<findChar(n, k);
    }
}