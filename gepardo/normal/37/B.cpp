#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n, mx, rg; cin >> n >> mx >> rg;
    int pc = mx;
    int hp = mx * 100;
    rg *= 100;
    int dmg = 0;

    vector < pair<int,int> > scr(n);
    vector < pair<int,int> > ans;

    for (int i = 0; i < n; i++)
    {
        cin >> scr[i].first >> scr[i].second;
        scr[i].first *= mx;
        scr[i].second *= 100;
    }

    int die = 0;

    for (int i = 0; i < 5000; i++)
    {
        hp -= dmg;
        hp = min(mx * 100, hp + rg);

        if (hp <= 0) { die = i; break; }

        int bsid = -1;

        for (int j = 0; j < n; j++)
        {
            if (hp > scr[j].first) continue;
            if (bsid == -1 || scr[j].second > scr[bsid].second) bsid = j;
        }

        if (bsid == -1) continue;
        dmg += scr[bsid].second;
        ans.push_back({i, bsid + 1});
        scr[bsid].first = -1;
    }

    if (hp <= 0)
    {
        cout << "YES" << endl << die << " " << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) cout << ans[i].first << " " << ans[i].second << endl;
    }
    else cout << "NO";


}