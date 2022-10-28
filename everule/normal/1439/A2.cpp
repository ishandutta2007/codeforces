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
struct operation{
    int x1,y1,x2,y2,x3,y3;
    operation(int x1,int y1,int x2, int y2,int x3, int y3) : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {}
    operation() {}
};
void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> grid(n);
    cin>>grid;
    vector<operation> ans;
    auto add = [&](operation &o){
        grid[o.x1][o.y1] = '1' + '0' - grid[o.x1][o.y1];
        grid[o.x2][o.y2] = '1' + '0' - grid[o.x2][o.y2];
        grid[o.x3][o.y3] = '1' + '0' - grid[o.x3][o.y3];
    };
    while(n>2 || m>2){
        if(n < m){
            for(int i=0;i<n;i++){
                if(grid[i][m-1] == '1'){
                    ans.emplace_back(i,m-1,i,m-2,i-1 + 2 * (i==0),m-2);
                    add(ans.back());
                }
            }
            --m;
        }
        else{
            for(int i=0;i<m;i++){
                if(grid[n-1][i] == '1'){
                    ans.emplace_back(n-1,i,n-2,i,n-2,i-1 + 2*(i==0));
                    add(ans.back());
                }
            }    
            --n;
        }
    }
    auto solved = [&](){
        int cnt = (grid[0][0] - '0') + (grid[0][1] - '0') + (grid[1][0] - '0') + (grid[1][1] - '0');
        if(cnt == 0) return true;
        auto choose = [&](int c0,int c1){
            vector<int> points;
            for(const auto &[x,y] : {pair(0,0), pair(0,1), pair(1,0), pair(1,1)}){
                if(c1 && grid[x][y] == '1'){
                    points.push_back(x);
                    points.push_back(y);
                    --c1;
                }
                if(c0 && grid[x][y] == '0'){
                    points.push_back(x);
                    points.push_back(y);
                    --c0;
                }
            }
            ans.emplace_back(points[0], points[1], points[2], points[3], points[4], points[5]);
            add(ans.back());
        };
        if(cnt == 1){
            choose(2,1);
        }
        if(cnt == 2){
            choose(2,1);
        }
        if(cnt == 3){
            choose(0,3);
        }
        if(cnt == 4){
            choose(0,3);
        }
        return false;
    };
    while(!solved()){}
    cout<<ans.size()<<"\n";
    for(const auto &[x1,y1,x2,y2,x3,y3] : ans){
        cout<<x1 + 1 <<" "<<y1 + 1 <<" "<<x2 + 1<<" "<<y2 + 1<<" "<<x3 + 1<<" "<<y3 + 1<<"\n";
    }
    //cout+grid;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}