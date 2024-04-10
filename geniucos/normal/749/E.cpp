#include<bits/stdc++.h>

using namespace std;

int N, a[100009], aib[100009];
long long M, pref[100009], suf[100009];
long double ans, aib2[2][100009];

void Clear () {for (int i=0; i<=N; i++) aib[i] = 0;}
void Updt (int pos) {while (pos <= N) aib[pos] ++, pos += pos - (pos & (pos - 1));}
int Qry (int pos) {int sum = 0; while (pos) sum += aib[pos], pos &= pos - 1; return sum;}

void Updt2 (int lin, int pos, long double val) {while (pos <= N) aib2[lin][pos] += val, pos += pos - (pos & (pos - 1));}
long double Qry2 (int lin, int pos) {long double sum = 0; while (pos) sum += aib2[lin][pos], pos &= pos - 1; return sum;}

void BuildPref ()
{
    for (int i=N; i>=1; i--)
    {
        pref[i] = Qry (a[i]);
        Updt (a[i]);
    }
    for (int i=1; i<=N; i++)
        pref[i] += pref[i - 1];
}

void BuildSuf ()
{
    for (int i=1; i<=N; i++)
    {
        suf[i] = Qry (N - a[i] + 1);
        Updt (N - a[i] + 1);
    }
    for (int i=N; i>=1; i--)
        suf[i] += suf[i + 1];
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N), M = 1LL * N * (N + 1) / 2;
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
BuildPref (), Clear (), BuildSuf (), Clear ();
for (int l=1; l<=N; l++)
    ans += (double) (N - l + 1) / M * 0.25 * l * (l - 1);
for (int i=1; i<=N; i++)
    ans += (double) (N - i + 1) / M * pref[i - 1],
    ans += (double) i / M * suf[i + 1];
/*for (int i=1; i<=N; i++)
    for (int j=i+1; j<=N; j++)
        if (a[i] > a[j])
            ans -= 0.5 * (j - i) * (j - i - 1) / M;*/
for (int i=N; i>=1; i--)
{
    int cnt = Qry (a[i]);
    long double s = Qry2 (0, a[i]), s2 = Qry2 (1, a[i]);
    ans -= (1.0 * i / N * i / (N + 1) * cnt + s2 - 2LL * i * s - s + 1.0 * i / N * cnt / (N + 1));
//    ans -= 0.5 / M * (1LL * cnt * i2 + s2 - 2LL * i * s - s + 1LL * cnt * i);
    Updt (a[i]);
    Updt2 (0, a[i], (long double)0.5 * i / M);
    Updt2 (1, a[i], (long double) i / N * i / (N + 1));
}
//printf ("%.15f\n", ans);
cout << setprecision (20) << ans << '\n';
return 0;
}