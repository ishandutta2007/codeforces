#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#ifdef ONLINE_JUDGE

#define fin cin
#define fout cout

#else

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);

#endif

struct TCast {
    int pow, dmg;

    TCast(int _pow = 0, int _dmg = 0)
        : pow(_pow)
        , dmg(_dmg)
    {
    }

    bool operator>(const TCast &a) const {
        if (dmg != a.dmg) {
            return dmg > a.dmg;
        }
        return pow > a.pow;
    }
};

int main() {
	fout.precision(10);
	fout << fixed;

    int N, mhp, reg;
    fin >> N >> mhp >> reg;

    vector<TCast> casts(N);
    for (int i = 0; i < N; ++i) {
        fin >> casts[i].pow >> casts[i].dmg;
    }

    int hp = mhp;
    int dps = 0;
    bool ok;
    int sec = 0;

    vector<pair<int, int> > evs;

    while (hp > 0) {
        //hp -= dps;
        hp = min(hp - dps + reg, mhp);
        if (hp <= 0) {
            ok = true;
            break;
        }
        
        int maxi = -1;
        for (int i = 0; i < N; ++i) {
            if (hp > 0 && 100 * hp <= casts[i].pow * mhp) {
                if (maxi < 0 || casts[i] > casts[maxi]) {
                    maxi = i;
                }
            }
        }
        if (maxi < 0 && dps <= reg) {
            ok = false;
            break;
        }
        if (maxi >= 0) {
            casts[maxi].pow = 0;
            dps += casts[maxi].dmg;
            evs.push_back(make_pair(sec, maxi + 1));
        }
        ++sec;
    }

    if (ok) {
        fout << "YES\n" << sec << ' ' << evs.size() << '\n';
        for (size_t i = 0; i < evs.size(); ++i) {
            fout << evs[i].first << ' ' << evs[i].second << '\n';
        }
    } else {
        fout << "NO\n";
    }

	return 0;
}