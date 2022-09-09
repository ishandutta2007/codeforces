#include<bits/stdc++.h>
using namespace std;
using LL = long long;
struct Pt{
    LL x, y;
}pt[4];
int p[4];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        for(int i = 0; i < 4; i += 1){
            cin >> pt[i].x >> pt[i].y;
            p[i] = i;
        }
        set<LL> sd;
        for(int i = 0; i < 4; i += 1)
            for(int j = 0; j < 4; j += 1){
                sd.insert(abs(pt[i].x - pt[j].x));
                sd.insert(abs(pt[i].y - pt[j].y));
            }
        //10
        //23
        LL ans = 1E18;
        do{
            for(LL d : sd){
                vector<LL> v = {pt[p[0]].x - d, pt[p[1]].x, pt[p[2]].x, pt[p[3]].x - d};
                vector<LL> w = {pt[p[0]].y - d, pt[p[1]].y - d, pt[p[2]].y, pt[p[3]].y};
                sort(v.begin(), v.end());
                sort(w.begin(), w.end());
                ans = min(ans, -v[0]-v[1]+v[2]+v[3]-w[0]-w[1]+w[2]+w[3]);
            }
        }while(next_permutation(p, p + 4));
        cout << ans << "\n";
    }
    return 0;
}