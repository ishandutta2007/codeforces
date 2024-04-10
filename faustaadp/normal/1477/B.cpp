#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll t, n, q, L[NN], R[NN];
string S, T;
ll ST[4 * NN];
ll LZ[4 * NN];
ll a[NN];
ll b[NN];
void turun(ll aa, ll bb, ll ee)
{
    if(LZ[ee])
    {
        ST[ee] = LZ[ee] * (bb - aa + 1);
        if(aa < bb)
        {
            LZ[ee * 2] = LZ[ee];
            LZ[ee * 2 + 1] = LZ[ee];
        }
        LZ[ee] = 0;
    }
}
void upd(ll aa, ll bb, ll cc, ll dd, ll ee, ll ff)
{
    turun(aa, bb, ee);
    if(bb < cc || dd < aa)
        return ;
    else
    if(cc <= aa & bb <= dd)
    {
        LZ[ee] = ff;
        turun(aa, bb, ee);
    }
    else
    {
        ll ce = (aa + bb) / 2;
        upd(aa, ce, cc, dd, ee * 2, ff);
        upd(ce + 1, bb, cc, dd, ee * 2 + 1, ff);
        ST[ee] = ST[ee * 2] + ST[ee * 2 + 1];
    }
}
ll que(ll aa, ll bb, ll cc, ll dd, ll ee)
{
    turun(aa, bb, ee);
    if(bb < cc || dd < aa)
        return 0;
    else
    if(cc <= aa & bb <= dd)
    {
        return ST[ee];
    }
    else
    {
        ll ce = (aa + bb) / 2;
        return que(aa, ce, cc, dd, ee * 2) + que(ce + 1, bb, cc, dd, ee * 2 + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        for(ll i = 1; i <= 4 * n; i++)
        {
            ST[i] = 0;
            LZ[i] = 0;
        }
        for(ll i = 1; i <= n; i++)
        {
            char ct;
            cin >> ct;
            a[i] = (ct == '1');
        }
        for(ll i = 1; i <= n; i++)
        {
            char ct;
            cin >> ct;
            b[i] = (ct == '1');
            if(!b[i])
                upd(1, n, i, i, 1, -1);
            else
                upd(1, n, i, i, 1, 1);
        }
        for(ll i = 1; i <= q; i++)
        {
            cin >> L[i] >> R[i];
        }
        ll gagal = 0;
        for(ll i = q; i >= 1; i--)
        {
            ll hz = que(1, n, L[i], R[i], 1);
            if(hz == 0)
            {
                gagal = 1;
                break;
            }
            ll ubah = 1;
            if(hz < 0)
                ubah = -1;
            upd(1, n, L[i], R[i], 1, ubah);
        }
        for(ll i = 1; i <= n; i++)
        {
            if(a[i] == 1 && que(1, n, i, i, 1) == -1)
            {
                gagal = 1;
                break;
            }
            if(a[i] == 0 && que(1, n, i, i, 1) == 1)
            {
                gagal = 1;
                break;
            }
        }
        if(gagal == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}