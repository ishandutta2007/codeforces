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
template<int n,int m,int p>
struct matrix{
    array<array<ll, m>, n> mat;
    void zeroout(){
        for(auto &v : mat){
            for(auto &x : v){
                x = 0;
            }
        }
    }
    matrix() {zeroout();}
    matrix(array<array<ll, n>, m> arr) : mat(arr) {}
    template<int k>
    matrix operator*(matrix<m,k,p> a){
        matrix<n,k,p> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int l=0;l<k;l++){
                    ans.mat[i][l] += this->mat[i][j] * a.mat[j][l];
                    ans.mat[i][l] %= p;
                }
            }
        }
        return ans;
    }
};
template<int n,int p>
matrix<n,n,p> matpower(matrix<n,n,p> base,ll power){
    matrix<n,n,p> ans;
    for(int i=0;i<base.mat.size();i++){
        ans.mat[i][i]=1;
    }
    while(power){
        if(power & 1){
            ans=ans*base;
        }
        base=base*base;
        power>>=1;
    }
    return ans;
}
const int p = 998244353;
const int st = 64;
int MEX(vector<int> &x){
    vector<bool> found(x.size());
    for(int i=0;i<x.size();i++){
        if(x[i]<x.size()){
            found[x[i]]=1;
        }
    }
    for(int i=0;i<x.size();i++){
        if(!found[i]){
            return i;
        }
    }
    return x.size();
}
int MEX(std::initializer_list<int> x){
    vector<bool> found(x.size());
    for(const auto &g : x){
        if(g < x.size()){
            found[g] = 1;
        }
    }
    for(int i=0;i<x.size();i++){
        if(!found[i]) return i;
    }
    return x.size();
}
const int lgn = 32;
void solve(){
    int n;
    cin>>n;
    vector<int> len(n);
    cin>>len;
    int m;
    cin>>m;
    vector<vector<pair<int,int>>> chosen(n);
    for(int i=0;i<m;i++){
        int x,y,c;
        cin>>x>>y>>c;
        --x;--c;
        chosen[x].push_back(pair(y,c));
    }
    array<array<int, 3>, 3> f;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>f[i][j];
        }
    }
    matrix<st,st,p> trans;
    array<matrix<st,st,p>, 3> colortrans;
    for(int c=0;c<3;c++){
        for(int g1 = 0; g1 < 4; g1 ++){
            for(int g2 = 0 ; g2 < 4 ; g2 ++){
                for(int g3 = 0 ; g3 < 4 ; g3 ++){
                    int st = (g1<<4) + (g2<<2) + g3;
                    vector<int> grundies;
                    if(f[c][0]) grundies.push_back(g3);
                    if(f[c][1]) grundies.push_back(g2);
                    if(f[c][2]) grundies.push_back(g1);
                    int g = MEX(grundies);
                    int st2 = (g2<<4) + (g3<<2) + g;
                    trans.mat[st][st2]++;
                    colortrans[c].mat[st][st2]++;
                }
            }
        }
    }
    vector<matrix<st,st,p>> transpower(lgn);
    transpower[0] = trans;
    for(int i=1;i<lgn;i++){
        transpower[i] = transpower[i-1] * transpower[i-1];
    }
    auto transpowerof = [&](matrix<1,st,p> &curr, int v){
        for(int i=0;i<lgn;i++){
            if((v>>i)&1){
                curr = curr * transpower[i];
            }
        }
    };
    auto brute = [&](int idx){
        array<ll, 4> ans = {0,0,0,0};
        function<void(int,vector<int>)> recurse = [&](int x, vector<int> grs){
            for(int c = 0 ; c < 3 ; c ++){
                bool flag = 0;
                for(const auto &[idx2,col] : chosen[idx]){
                    if(x == idx2 && col != c) flag = 1;
                }
                if(flag) continue;
                vector<int> curr;
                for(int i=0;i<3;i++){
                    if(x-i-2 < 0 || !f[c][i]) continue;
                    curr.push_back(grs[x-i-2]);
                }
                grs.push_back(MEX(curr));
                if(x == len[idx]){
                    ans[grs.back()]++;
                }
                else{
                    recurse(x+1, grs);
                }
                grs.pop_back();
            }
        };
        recurse(1, vector<int>());
        return ans;
    };
    auto computebase = [&](int idx){
        auto check = [&](int idx1, int c){
            for(const auto &[idx2, val] : chosen[idx]){
                if(idx2 > idx1) break;
                if(idx1 == idx2 && val != c) return false;
            }
            return true;
        };
        matrix<1,st,p> curr;
        for(int c1 = 0 ; c1 < 3 ; c1 ++){
            for(int c2 = 0 ; c2 < 3 ; c2 ++){
                for(int c3 = 0 ; c3 < 3 ; c3 ++){
                    if(check(1,c1) && check(2,c2) && check(3, c3)){
                        int g = 0;
                        if(f[c2][0]) g+=(1<<2);
                        if(f[c3][0] && f[c3][1]){
                            if(g == 0){
                                g += 1;
                            }
                            else{
                                g += 2;
                            }
                        }
                        else if(f[c3][0]){
                            if(g == 0){
                                g += 1;
                            }
                        }
                        else if(f[c3][1]){
                            g ++;
                        }
                        //if(len[idx] == 4) cout<<g<<"\n";
                        curr.mat[0][g] ++;
                    }
                }
            }
        }
        return curr;
    };
    vector<array<ll, 4>> grundies(n, {0,0,0,0});
    for(int i=0;i<n;i++){
        sort(chosen[i].begin(), chosen[i].end());
        if(len[i] < 4){
            grundies[i] = brute(i);
            continue;
        }
        auto curr = computebase(i);
        int prev = 3;
        for(const auto &[v,col] : chosen[i]){
            if(v <= prev) continue;
            transpowerof(curr, v - prev - 1);
            curr = curr * colortrans[col];
            prev = v;
        }
        if(prev != len[i]){
            transpowerof(curr, len[i] - prev);
        }
        for(int j=0;j<st;j++){
            grundies[i][j&3] += curr.mat[0][j];
            grundies[i][j&3] %= p;
        }
    }
    auto convolute = [&](array<ll, 4> x1, array<ll, 4> x2){
        array<ll, 4> ans = {0,0,0,0};
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                ans[i^j] += x1[i] * x2[j];
                ans[i^j] %= p;
            }
        }
        return ans;
    };
    array<ll,4> ans = {1,0,0,0};
    for(const auto &arr : grundies){
        ans = convolute(ans, arr);
    }
    cout<<ans[0]<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}