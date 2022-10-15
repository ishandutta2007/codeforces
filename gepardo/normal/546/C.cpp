#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n;

struct deState { vector<int> a, b; };

deState fromState(long long s)
{
    deState d;
    bool pa = true;
    for (int i = 0; i <= n; i++)
    {
        long long v = s & 15;
        s >>= 4;
        if (v == 0) { pa = false; continue; }
        if (pa) d.a.push_back(v); else d.b.push_back(v);
    }
    return d;
}

long long toState(deState d)
{
    long long s = 0;
    int shl = 0;
    for (int i = 0; i < d.a.size(); i++)
        s += (long long)d.a[i] << shl,
        shl += 4;
    shl += 4;
    for (int i = 0; i < d.b.size(); i++)
        s += (long long)d.b[i] << shl,
        shl += 4;
    return s;
}

int win(long long st)
{
    deState a = fromState(st);
    if (a.a.size() == 0 && a.b.size() == 0) return 3;
    if (a.a.size() == 0) return 2;
    if (a.b.size() == 0) return 1;
    return 0;
}

long long fight(long long st)
{
    deState a = fromState(st), b;
    if (a.a[a.a.size() - 1] > a.b[a.b.size() - 1])
    {
        for (int i = 0; i < (a.b.size() - 1); i++) b.b.push_back(a.b[i]);
        b.a.push_back(a.a[a.a.size() - 1]);
        b.a.push_back(a.b[a.b.size() - 1]);
        for (int i = 0; i < (a.a.size() - 1); i++) b.a.push_back(a.a[i]);
    }
    else if (a.b[a.b.size() - 1] > a.a[a.a.size() - 1])
    {
        for (int i = 0; i < (a.a.size() - 1); i++) b.a.push_back(a.a[i]);
        b.b.push_back(a.b[a.b.size() - 1]);
        b.b.push_back(a.a[a.a.size() - 1]);
        for (int i = 0; i < (a.b.size() - 1); i++) b.b.push_back(a.b[i]);
    }
    return toState(b);
}

deState inState()
{
    deState d;
    int k;
    cin >> k;
    d.a.resize(k);
    for (int i = 0; i < k; i++) cin >> d.a[k - i - 1];
    cin >> k;
    d.b.resize(k);
    for (int i = 0; i < k; i++) cin >> d.b[k - i - 1];
    return d;
}

void outState(deState d)
{
    cout << "state::[a = (";
    for (int i = 0; i < d.a.size(); i++)
    {
        if (i != 0) cout << ", ";
        cout << d.a[i];
    }
    cout << "), b = (";
    for (int i = 0; i < d.b.size(); i++)
    {
        if (i != 0) cout << ", ";
        cout << d.b[i];
    }
    cout << ")];" << endl;
}

int main()
{
    cin >> n;
    deState d = inState();
    //outState(d);
    long long v = toState(d);
    //cout << v << endl;
    set<long long> s;
    int c = 0;
    for(;;)
    {
        //cout << v << " " << win(v) << endl;
        //outState(fromState(v));
        if (win(v) != 0)
        {
            cout << c << " " << win(v) << endl;
            return 0;
        }
        if (s.count(v) != 0)
        {
            cout << -1 << endl;
            return 0;
        }
        c++;
        s.insert(v);
        v = fight(v);
    }


}