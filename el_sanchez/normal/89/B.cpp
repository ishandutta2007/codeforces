#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define odd(x) ((x) % 2 == 1)

typedef long long int64;

const int MAXN = (int)110;
const int INF = (int)1E9;
const long double eps = 1e-9;
const long double pi = 3.1415926535897932384626433832795;

using namespace std;

struct widget {
    bool packed;
    int64 border, spacing, type, numch, childs[MAXN], height, width;
};

int64 val[2], n, elem;
string current, c2, name;
map<string, int> names;
vector<widget> widgets;
widget temp;

void init() {
    temp.packed = 0;
    temp.border = 0;
    temp.height = 0;
    temp.numch = 0;
    temp.spacing = 0;
    temp.type = 0;
    temp.width = 0;
}

void replace_extra(string* str) {
    replace(all(*str), '.', ' ');
    replace(all(*str), ',', ' ');
    replace(all(*str), '(', ' ');
    replace(all(*str), ')', ' ');
}

int pack(int id) {
    if (widgets[id].packed)
        return 0;
    else
        widgets[id].packed = 1;
    forn(j, widgets[id].numch) {
        int childid = widgets[id].childs[j];
        pack(childid);
        if (j == 0) {
            widgets[id].width = widgets[childid].width + 2 * widgets[id].border;
            widgets[id].height = widgets[childid].height + 2 * widgets[id].border;
        } else
            if (widgets[id].type == 1) {
                widgets[id].width += widgets[childid].width + widgets[id].spacing;
                widgets[id].height = max(widgets[id].height, widgets[childid].height + 2 * widgets[id].border);
            } else {
                widgets[id].width = max(widgets[id].width, widgets[childid].width + 2 * widgets[id].border);
                widgets[id].height += widgets[childid].height + widgets[id].spacing;
            }
    }
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    elem = 0;
    cin >> n;
    forn(i, n) {
        cin >> current;
        init();

        if (current == "Widget") {
            cin >> current;
            replace_extra(&current);
            istringstream sin(current);
            sin >> name >> val[0] >> val[1];
            names[name] = elem;
            elem++;
            temp.width = val[0];
            temp.height = val[1];
            widgets.push_back(temp);
            continue;
        }

        if ((current == "VBox") || (current == "HBox")) {
            cin >> name;
            names[name] = elem;
            elem++;
            temp.type = (current == "VBox") + 1; // 1 = HBox, 2 = VBox
            widgets.push_back(temp);
            continue;
        }

        c2 = current;
        replace_extra(&c2);
        istringstream sin(c2);
        sin >> current >> name;

        if (name == "set_border") {
            sin >> val[0];
            widgets[names[current]].border = val[0];
            continue;
        }

        if (name == "set_spacing") {
            sin >> val[0];
            widgets[names[current]].spacing = val[0];
            continue;
        }

        sin >> name;
        val[0] = widgets[names[current]].numch;
        widgets[names[current]].numch++;

        widgets[names[current]].childs[val[0]] = names[name];
    }

    for(map<string, int>:: iterator st = names.begin(), en = names.end(); st != en; ++st) {
        current = st -> fi;
        val[0] = st -> se;
        pack(val[0]);
        cout << current << ' ' << widgets[val[0]].width << ' ' << widgets[val[0]].height << endl;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}