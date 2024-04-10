#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    vector<string> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> clr(n, 0);
    int cnt = 0;
    vector<vector<int> > data;
    for (int i = 0; i < n; i++){
        if (clr[i] == 0){
            data.pb(vector<int>(0));
            cnt++;
            vector<int> st(1, i);
            clr[i] = cnt;
            while (!st.empty()){
                int v = st.back();
                data[cnt - 1].pb(p[v]);
                st.pop_back();
                for (int j = 0; j < n; j++){
                    if (a[v][j] == '1' && clr[j] == 0){
                        st.pb(j);
                        clr[j] = cnt;
                    }
                }
            }
        }
    }
    for (int i = 0; i < data.size(); i++){
        sort(all(data[i]));
    }
    vector<int> q(cnt, 0);
    for (int i = 0; i < n; i++){
        cout << data[clr[i] - 1][q[clr[i] - 1]++] << " ";
    }
    cout << "\n";

    return 0;
}