#include <iostream>
#include <vector>

using namespace std;

struct symbol {char value; int prev; int next; };

void del(vector<symbol> & v, int i) {
    int next = v[i].next, prev = v[i].prev;
    if (v[i].prev != -1) v[prev].next = next;
    if (v[i].next != -1) v[next].prev = prev;
}

int ans(char *str, int l, int r) {
    int a[10], cp = 0;
    bool dp = true;
    vector<symbol> v;
    for (int i=l; i<=r; i++) {
        symbol s;
        s.value = str[i];
        if (i>l) s.prev = i-1-l;
        else s.prev = -1;
        if (i<r) s.next = i+1-l;
        else s.next = -1;
        v.push_back(s);
    }
    for (int i=0; i<10; i++) a[i] = 0;

    while (cp != -1) {
        if (v[cp].value >= '0' && v[cp].value <= '9') {
            a[v[cp].value - '0']++;
            if (v[cp].value > '0') v[cp].value--;
            else del(v, cp);
            cp = dp ? v[cp].next : v[cp].prev;
        } else {
            dp = (v[cp].value == '>') ? 1 : 0;
            int cp2 = cp;
            cp = dp ? v[cp].next : v[cp].prev;
            if (cp != -1 && (v[cp].value == '>' || v[cp].value == '<')) del(v, cp2);
        }
    }
    for (int i=0; i<10; i++) cout << a[i] << ' ';
}

int main()
{
    int n, q, *l, *r;
    char *str;
    cin >> n >> q;
    l = new int[q];
    r = new int[q];
    str = new char[100];
    cin >> str;
    for (int i=0; i<q; i++) cin >> l[i] >> r[i];
    for (int i=0; i<q; i++) {
        ans(str, l[i]-1, r[i] - 1);
        cout << endl;
    }
    return 0;
}