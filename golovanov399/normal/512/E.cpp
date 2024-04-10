#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

vector<pair<int, int> > solve(const vector<pair<int, int> >& a){
    int n = a.size() + 3;
    vector<pair<int, int> > ans;
    vector<int> p;
    vector<set<int> > b(n);
    p.pb(2);
    p.pb(n);
    for (auto x : a){
        if (x.x == 1 || x.y == 1)
            p.pb(x.x + x.y - 1);
        b[x.x - 1].insert(x.y - 1);
        b[x.y - 1].insert(x.x - 1);
    }
    for (int i = 0; i < n; i++){
        b[i].insert((i + 1) % n);
        b[(i + 1) % n].insert(i);
    }
    sort(all(p));
    while (p.size() < n - 1){
        int i = 0;
        while (p[i] == i + 2) i++;
        ans.pb(mp(i + 1, p[i]));
        int x = i;
        int y = p[i] - 1;
        b[x].erase(y);
        b[y].erase(x);
        i = 1;
        for (; i < n; i++){
            if (b[x].find(i) != b[x].end() && b[y].find(i) != b[y].end())
                break;
        }
        b[0].insert(i);
        b[i].insert(0);
        p.pb(i + 1);
        i = p.size() - 1;
        while (p[i] < p[i - 1]){
            swap(p[i], p[i - 1]);
            i--;
        }
    }
    return ans;
}

vector<pair<int, int> > solve2(const vector<pair<int, int> >& a){
    int n = a.size() + 3;
    vector<pair<int, int> > ans;
    vector<int> p;
    vector<set<int> > b(n);
    p.pb(2);
    p.pb(n);
    for (auto x : a){
        if (x.x == 1 || x.y == 1)
            p.pb(x.x + x.y - 1);
        b[x.x - 1].insert(x.y - 1);
        b[x.y - 1].insert(x.x - 1);
    }
    for (int i = 0; i < n; i++){
        b[i].insert((i + 1) % n);
        b[(i + 1) % n].insert(i);
    }
    sort(all(p));
    while (p.size() < n - 1){
        int i = 0;
        while (p[i] == i + 2) i++;
        int x = i;
        int y = p[i] - 1;
        b[x].erase(y);
        b[y].erase(x);
        i = 1;
        for (; i < n; i++){
            if (b[x].find(i) != b[x].end() && b[y].find(i) != b[y].end())
                break;
        }
        b[0].insert(i);
        b[i].insert(0);
        p.pb(i + 1);
        ans.pb(mp(1, i + 1));
        i = p.size() - 1;
        while (p[i] < p[i - 1]){
            swap(p[i], p[i - 1]);
            i--;
        }
    }
    return ans;
}

int main(){

    int n;
    cin >> n;
    vector<pair<int, int> > a(n - 3), b(n - 3);
    for (itn i = 0; i < n - 3; i++){
        cin >> a[i].x >> a[i].y;
    }
    for (itn i = 0; i < n - 3; i++){
        cin >> b[i].x >> b[i].y;
    }
    auto ans1 = solve(a), ans2 = solve2(b);
    reverse(all(ans2));
    cout << ans1.size() + ans2.size() << "\n";
    for (int i = 0; i < ans1.size(); i++){
        cout << ans1[i].x << " " << ans1[i].y << "\n";
    }
    for (int i = 0; i < ans2.size(); i++){
        cout << ans2[i].x << " " << ans2[i].y << "\n";
    }

    return 0;
}