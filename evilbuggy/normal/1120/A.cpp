#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[500005];
int b[500005];
map<int,int> freq,  req;

void add(int x){
    freq[x]++;

    if(req.find(x) != req.end()){
        req[x]--;
        if(!req[x])req.erase(x);
    }
}

void rem(int x){
    if(freq[x] > b[x]){
        freq[x]--;
        if(!freq[x])freq.erase(x);
    }else{
        if(b[x] > 0)req[x]++;
        freq[x]--;
        if(!freq[x])freq.erase(x);
    }
}

void print(int l, int r, int k){
    cout<<(r-l+1)-k<<endl;
    int cnt = (r-l+1)-k;
    for(int i = l; i <= r; i++){
        if(!cnt)break;
        if(b[a[i]] > 0){
            b[a[i]]--;
        }else{
            cout<<i<<" ";
            cnt--;
        }
    }
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

    int n, m, k, s, x;
    cin>>m>>k>>n>>s;
    for(int i = 1; i <= m; i++){
        cin>>a[i];
    }
    memset(b, 0, sizeof(b));
    for(int i = 1; i <= s; i++){
        cin>>x;
        b[x]++;
        req[x]++;
    }
    int mxl = k + (m - n*k);
    int r = 0;
    for(int l = 1; l <= m; l++){
        while(r < m && !req.empty()){
            r++;
            add(a[r]);
        }
        while(r < m && r - l + 1 < k){
            r++;
            add(a[r]);
        }
        if(req.empty()){
            int cnt = (l-1)/k + (m-r)/k;
            if(r - l + 1 <= mxl && cnt + 1 >= n && r - l + 1 >= k){
                print(l, r, k);
                exit(0);
            }
        }
        rem(a[l]);
    }
    cout<<-1<<endl;
}