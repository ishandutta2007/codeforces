#include<bits/stdc++.h>
using namespace std;
using LL = long long;
LL sum = 0, pre = 0;
multiset<int> db, oc;
multiset<int> bg, sm;
void fix(){
    if(bg.size() > db.size()){
        int x = *bg.begin();
        bg.erase(bg.begin());
        pre -= x;
        sm.insert(x);
    }
    if(bg.size() < db.size()){
        int x = *prev(sm.end());
        sm.erase(prev(sm.end()));
        pre += x;
        bg.insert(x);
    }
}
void add(int d){
    if(sm.empty() or d >= *prev(sm.end())){
        bg.insert(d);
        pre += d;
    }
    else sm.insert(d);
}
void remove(int d){
    if(bg.find(d) != bg.end()){
        bg.erase(bg.find(d));
        pre -= d;
    }
    else sm.erase(sm.find(d));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    for(cin >> n; n; n -= 1){
        int tp, d;
        cin >> tp >> d;
        sum += d;
        if(d > 0){
            if(tp == 0) oc.insert(d);
            else db.insert(d);
            add(d);
        }
        else{
            d = -d;
            if(tp == 0) oc.erase(d);
            else db.erase(d);
            remove(d);
        }
        fix();
        if(oc.empty() or (not db.empty() and *db.begin() >= *prev(oc.end()))){
            LL ans = sum + pre - *db.begin();
            if(oc.size()) ans += *prev(oc.end());
            cout << ans << "\n";
        }
        else cout << sum + pre << "\n";
    }
    return 0;
}