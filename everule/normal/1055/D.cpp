#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
template<typename T>
ostream& operator+(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}
template<typename T>
ostream& operator*(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out+x;
    }
    return out;
}
template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}
void solve(){
    int n;
    cin>>n;
    vector<array<string, 2>> seq(n);
    for(int i=0;i<n;i++) cin>>seq[i][0];
    for(int i=0;i<n;i++) cin>>seq[i][1];
    int idx = find_if(seq.begin(), seq.end(), [&](array<string, 2>& var){
        return var[0] != var[1];
    }) - seq.begin();
    auto findiff = [&](int idx){
        int l = -1, r = -1;
        for(int i=0;i<seq[idx][0].size();i++){
            if(seq[idx][0][i] != seq[idx][1][i]){
                if(l==-1) l=i;
                r=i;
            }
        }
        return pair(l,r);
    };
    auto [l,r] = findiff(idx);
    string gl, gr;
    for(int i=l-1;i>=0;--i){
        gl.push_back(seq[idx][0][i]);
    }
    for(int i=r+1;i<seq[idx][0].size();i++){
        gr.push_back(seq[idx][0][i]);
    }
    string m1 = seq[idx][0].substr(l,r-l+1);
    string m2 = seq[idx][1].substr(l,r-l+1);
    for(int i=0;i<n;i++){
        auto [li, ri] = findiff(i);
        if(li == -1 && ri == -1) continue;
        if(ri-li != r-l){
            cout<<"NO";
            return;
        }
        for(int j=0;j<=r-l;j++){
            if(seq[i][0][li+j] != seq[idx][0][l+j] || seq[i][1][li+j] != seq[idx][1][l+j]){
                cout<<"NO\n";
                return;
            }
        }
        gl.resize(li);
        for(int k=li-1,j=0;k>=0 && j<gl.size();--k,j++){
            if(seq[i][0][k] != gl[j]){
                gl.resize(j);
                break;
            }
        }
        gr.resize(seq[i][0].size() - ri - 1);
        for(int k=ri+1,j=0;k<seq[i][0].size() && j<gr.size();k++, j++){
            if(seq[i][0][k] != gr[j]){
                gr.resize(j);
                break;
            }
        }
    }
    reverse(gl.begin(), gl.end());
    string a1 = gl + m1 + gr;
    string a2 = gl + m2 + gr;
    auto pifunc = [&](string s){
        int n = (int)s.length();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return pi;
    };
    vector<int> pi = pifunc(a1);
    auto operate = [&](string s){
        int n = a1.size();
        int m = s.size();
        int r = -1;
        for(int i=0,j=0;i<m;i++){
            while(j > 0 && s[i] != a1[j]){
                j = pi[j-1];
            }
            if(s[i] == a1[j]) ++j;
            if(j == n){
                r = i;
                break;
            }
        }
        if(r == -1){
            return s;
        }
        int l = r - n + 1;
        for(int i=0;i<n;i++){
            s[l+i] = a2[i];
        }
        return s;
    };
    for(int i=0;i<n;i++){
        if(operate(seq[i][0]) != seq[i][1]){
            cout<<"NO\n\n";
            return;
        }
    }
    cout<<"YES\n";
    cout<<a1<<"\n"<<a2<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}