#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

int n, m, k;
int kolko;

long long int oduzmi = 0;
long long int suma;

vector <pair <int, int> > svi;
vector <int> poz;

int main()
{
    cin >> n >> m >> k;
    kolko = n - m * k;
    int x;
    REP(i, 0, n)
    {
        scanf("%d", &x);
        suma += x;
        svi.push_back(make_pair(x, i));
    }
    sort(svi.begin(), svi.end());
    REP(i, 0, kolko)
    {
        poz.push_back(svi[i].second);
        oduzmi += svi[i].first;
    }
    sort(poz.begin(), poz.end());
    suma -= oduzmi;
    cout << suma << endl;
    int p = 0, br = 0;
    int cnt = 0;
    REP(i, 0, n)
    {
        if(p < poz.size() && poz[p] == i) {p++; continue;}
        br++;
        if(br == m && i != n - 1 && cnt < k - 1)
        {
            br = 0;
            cnt++;
            printf("%d ", i + 1);
        }
    }
    return 0;
}