#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    string s;
    cin>>s;
    priority_queue<pair<string,int>, vector<pair<string,int> >, greater<pair<string,int> > > pq;
    int k;
    cin>>k;
    string t;
    int pos;
    for(int i = 0; i < s.size(); i++){
        t = s[i];
        pq.push({t, i});
    }
    while(!pq.empty() && k){
        t = pq.top().first;
        pos = pq.top().second;
        pq.pop();
        k--;
        if(!k){
            cout<<t<<endl;
            exit(0);
        }
        if(pos + 1 < s.size()){
            pq.push({t + s[pos + 1], pos + 1});
        }
    }
    cout<<"No such line."<<endl;
}