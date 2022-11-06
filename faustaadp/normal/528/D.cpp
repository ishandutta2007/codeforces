#include<bits/stdc++.h>
using namespace std;
// typedef long long int;
typedef double ld;
typedef complex<ld> cd;
typedef vector<cd> vcd; 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int t, n, m, k;
int x[401010];
char a[401010];
char b[401010];
int A[401010];
int B[401010];
int z[401010];
ld PI = acos(-1);
void fft(vcd &arr, int rev)
{
    int sz = arr.size();

    for(int i = 1, j = 0; i < sz; i++)
    {
        int bit = sz >> 1;
        for(; j >= bit; bit >>= 1)
            j -= bit;
        j += bit;
        if(i < j)
            swap(arr[i], arr[j]);
    }

    for(int bes = 2; bes <= sz; bes <<= 1)
    {
        double sudut = 2.0 * PI / bes;
        if(rev)
            sudut *= -1.0;
        cd wn(cos(sudut), sin(sudut));
        for(int i = 0; i < sz; i += bes)
        {
            cd w(1);
            for(int j = 0; j < (bes / 2); j++)
            {
                cd u = arr[i + j], v = arr[i + j + bes / 2] * w;
                arr[i + j] = u + v;
                arr[i + j + bes / 2] = u - v;
                w *= wn;
            }
        }
    }

    if(rev)
        for(int i = 0; i < sz; i++)
            arr[i] /= sz;
}
void hai(char ct)
{
    int kir = 1;
    for(int i = 1; i <= n; i++)
        A[i] = 0;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] != ct)continue;
        kir = max(kir, i - k);
        for(int j = kir; j <= i + k; j++)
            A[j] = 1;
        kir = max(kir, i + k + 1);
    }
    for(int i = 1; i <= m; i++)
        if(b[m - i + 1] == ct)
            B[i] = 1;
        else
            B[i] = 0;
    vcd va(n), vb(m);
    int bes = n + m - 1;
    for(int i = 0; i < n; i++)
        va[i] = A[i + 1];
    for(int i = 0; i < m; i++)
        vb[i] = B[i + 1];
    int tmp = 1;
    while(tmp < bes)
        tmp *= 2;
    for(int i = n; i < tmp; i++)
        va.pb(0);
    for(int i = m; i < tmp; i++)
        vb.pb(0);
    fft(va, 0);
    fft(vb, 0);
    for(int i = 0; i < tmp; i++)
        va[i] *= vb[i];
    fft(va, 1);
    for(int i = m - 1 ; i <= n - 1; i++)
    {
        z[i - m + 2] += (int)(va[i].real() + 0.5);
        // cout << ct << " " << i - m + 2 << " " << (int)(va[i].real() + 0.5) << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= m; i++)
        cin >> b[i];
    hai('A');
    hai('C');
    hai('G');
    hai('T');
    int jaw = 0;
    for(int i = 1; i <= n; i++)
    {
        // cout << i << " " << z[i] << "__\n";
        jaw += (z[i] == m);
    }
    cout << jaw << "\n";
}