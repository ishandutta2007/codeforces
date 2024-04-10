#include <bits/stdc++.h>
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
const int INF = 1e9 + 7; 
void solve(){
    int n;
    cin>>n;
    array<vector<array<int, 2>>, 3> px, py;
    for(int i=0;i<3;i++) px[i].clear(), py[i].clear();
    for(int i=0;i<n;i++){
        int x,y,c;
        cin>>x>>y>>c;
        --c;
        px[c].push_back({x, y});
        py[c].push_back({y, x});
    }
    for(int i=0;i<3;i++) assert(px[i].size() == n / 3 && py[i].size() == n / 3);
    for(int i=0;i<3;i++){
        sort(px[i].begin(), px[i].end());
        sort(py[i].begin(), py[i].end());
        for(auto &[y, x] : py[i]) swap(y, x);
    }
    int mn = 1, mx = n / 3;
    while(mn < mx){
        int mid = (mn + mx + 1) / 2;
        vector<int> co = {0, 1, 2};
        if([&](){
            do{
                for(int msk=0;msk<16;msk++){
                    if(msk % 4 == msk / 4) continue;
                    int mnx = -INF, mxx = INF, mny = -INF, mxy = INF;
                    if(msk % 4 == 0){
                        mnx = px[co[0]][mid - 1][0] + 1;
                        if(msk / 4 == 1){
                            int cnt = 0;
                            for(int i=n/3-1;i>=0 && cnt < mid;--i){
                                if(px[co[1]][i][0] >= mnx){
                                    cnt++;
                                }
                                mxx = px[co[1]][i][0] - 1;
                            }
                            if(cnt < mid) continue;
                        }
                        if(msk / 4 == 2){
                            int cnt = 0;
                            for(int i=0;i<n/3 && cnt < mid;i++){
                                if(py[co[1]][i][0] >= mnx){
                                    cnt++;
                                }
                                mny = py[co[1]][i][1] + 1;
                            }
                            if(cnt < mid) continue;
                        }
                        if(msk / 4 == 3){
                            int cnt = 0;
                            for(int i=n/3-1;i>=0 && cnt < mid;--i){
                                if(py[co[1]][i][0] >= mnx){
                                    cnt++;
                                }
                                mxy = py[co[1]][i][1] - 1;
                            }
                            if(cnt < mid) continue;
                        }
                    }
                    if(msk % 4 == 1){
                        mxx = px[co[0]][n/3-mid][0] - 1;
                        if(msk / 4 == 0){
                            int cnt = 0;
                            for(int i=0;i<n/3 && cnt < mid;i++){
                                if(px[co[1]][i][0] <= mxx){
                                    cnt++;
                                }
                                mnx = px[co[1]][i][0] + 1;
                            }
                            if(cnt < mid) continue;
                        }
                        if(msk / 4 == 2){
                            int cnt = 0;
                            for(int i=0;i<n/3 && cnt < mid;i++){
                                if(py[co[1]][i][0] <= mxx){
                                    cnt++;
                                }
                                mny = py[co[1]][i][1] + 1;
                            }
                            if(cnt < mid) continue;
                        }
                        if(msk / 4 == 3){
                            int cnt = 0;
                            for(int i=n/3-1;i>=0 && cnt < mid;--i){
                                if(py[co[1]][i][0] <= mxx){
                                    cnt++;
                                }
                                mxy = py[co[1]][i][1] - 1;
                            }
                            if(cnt < mid) continue;
                        }
                    }
                    if(msk % 4 == 2){
                        mny = py[co[0]][mid - 1][1] + 1;
                        if(msk / 4 == 0){
                            int cnt = 0;
                            for(int i=0;i<n/3 && cnt < mid;i++){
                                if(px[co[1]][i][1] >= mny){
                                    cnt++;
                                }
                                mnx = px[co[1]][i][0] + 1;
                            }
                            if(cnt < mid) continue;
                        }
                        if(msk / 4 == 1){
                            int cnt = 0;
                            for(int i=n/3-1;i>=0 && cnt < mid;--i){
                                if(px[co[1]][i][1] >= mny){
                                    cnt++;
                                }
                                mxx = px[co[1]][i][0] - 1;
                            }
                            if(cnt < mid) continue;
                        }
                        if(msk / 4 == 3){
                            int cnt = 0;
                            for(int i=n/3-1;i>=0 && cnt < mid;--i){
                                if(py[co[1]][i][1] >= mny){
                                    cnt++;
                                }
                                mxy = py[co[1]][i][1] - 1;
                            }
                            if(cnt < mid) continue;
                        }
                    }
                    if(msk % 4 == 3){
                        mxy = py[co[0]][(n/3)-mid][1] - 1;
                        if(msk / 4 == 0){
                            int cnt = 0;
                            for(int i=0;i<n/3 && cnt < mid;i++){
                                if(px[co[1]][i][1] <= mxy){
                                    cnt++;
                                }
                                mnx = px[co[1]][i][0] + 1;
                            }
                            if(cnt < mid) continue;
                        }
                        if(msk / 4 == 1){
                            int cnt = 0;
                            for(int i=n/3-1;i>=0 && cnt < mid;--i){
                                if(px[co[1]][i][1] <= mxy){
                                    cnt++;
                                }
                                mxx = px[co[1]][i][0] - 1;
                            }
                            if(cnt < mid) continue;
                        }
                        if((msk / 4) == 2){
                            int cnt = 0;
                            for(int i=0;i<(n/3) && cnt < mid;i++){
                                if(py[co[1]][i][1] <= mxy){
                                    cnt++;
                                }
                                mny = py[co[1]][i][1] + 1;
                            }
                            if(cnt < mid) continue;
                        }
                    }
                    int cnt = 0;
                    if(mnx >= mxx || mny >= mxy) continue;
                    for(int i=0;i<n/3;i++){
                        if(mnx <= px[co[2]][i][0] && px[co[2]][i][0] <= mxx && px[co[2]][i][1] >= mny && px[co[2]][i][1] <= mxy) cnt++;
                    }
                    if(cnt < mid) continue;
                    return true;
                }
            }while(next_permutation(co.begin(), co.end()));
            return false;
        }()){
            mn = mid;
        }
        else{
            mx = mid - 1;
        }
    }
    cout<<3 * mn<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}