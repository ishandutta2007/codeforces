    //g++ -std=c++17 -Wall t.cpp -o test -lm -g -O2
    #include <bits/stdc++.h>
    #define ff first
    #define ss second
    #define ll long long
    #define ld long double
    #define pb push_back
    #define eb emplace_back
    #define mp make_pair
    #define mt make_tuple
    #define pii pair<int, int>
    #define vi vector<int>
    #define vl vector<ll>
    #define vii vector<pii>
    #define sws ios_base::sync_with_stdio(false);cin.tie(NULL)
    #define endl '\n'
    #define teto(a, b) (a+b-1)/(b)
     
    const int MAX = 300010;
    const int MOD = 998244353;
    const int INF = 0x3f3f3f3f;
    const ll LLINF = 0x3f3f3f3f3f3f3f3f;
    const ld EPS = 1e-8;
    const ld PI = acosl(-1.0);
     
    // End - Template //
     
    using namespace std;
     
    int a[101], b[101], v[101];
    bool side[101];
    int hl, hr, n;
    ld H=1e2, W=1e5;
    int resp=0;
    bool visited[101];
     
    void solve(int num, int ini){ // nmero de rebatidas / comea pro teto ou pro cho
        memset(visited, false, sizeof(visited));
        int sum=0;
        ld k = 0;
        if(num&1)
            if(ini) k = (2*H-hr-hl + (num-1)*H)/W;
            else k = (hr+hl + (num-1)*H)/W;
        else
            if(ini) k = (H-hl+hr + (num-1)*H)/W;
            else k = (H+hl-hr + (num-1)*H)/W;
        
        for(int i=ini;i<ini+num;i++){ // 0-floor / 1-ceil
            ld pos;
            if(ini) pos = (H*i - hl)/k;
            else pos = (H*i + hl)/k;
     
            for(int j=0;j<n;j++){
                if(side[j]==(i%2) and a[j]<=pos and pos<=b[j]){
                    if(visited[j]) return;
                    sum+=v[j];
                    visited[j]=true;
                    break;
                }
                if(j==n-1) return;
            }
        }
     
        resp = max(resp, sum);
    }
     
    int main()
    {sws;
     
        cout << fixed << setprecision(10);
        cin >> hl >> hr >> n;
        int V, A, B;
        char c;
     
        for(int i=0;i<n;i++){
            cin >> V >> c >> A >> B;
            side[i]=(c=='T');
            a[i]=A;b[i]=B;v[i]=V;
        }
     
        for(int i=1;i<n;i++){
            solve(i, 0);
            solve(i, 1);
        }
        
        cout << resp << endl;
     
        return 0;
        
    }