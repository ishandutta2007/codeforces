#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define fr front()
#define sqr(a) ((a)*(a))
#define y1 Enkognit

using namespace std;

ll n, m, l, r, x, y, a[300001], sum;
ll b[11];

int main()
{
    //freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    cin >> n;
    for (int it = 0; it < n; it++)
    {
        string s;
        string d1={}, d2={}, d={};
        vector <char> v;
        cin >> s;
        ll kol[30];
        for (int i = 0; i < 30; i++) kol[i]=0;
        for (int i = 0; i < s.size(); i++)
        {
            if (kol[s[i]-'a']==0) v.pb(s[i]);
            kol[s[i]-'a']++;
        }
        sort(v.begin(),v.end());
        ll p=-1;
        //if (v.size()==2 || v.size()==3) {cout << "No answer\n";continue;}
        if (v.size()==1) {cout << s << "\n";continue;}
        for (int i = 0; i < v.size(); i++)
            if (v[i]%2) d1+=v[i]; else d2+=v[i];
        //cout << d << "\n";
        bool tt=0;
        if (d1.size()==0 || d2.size()==0) tt=1;
        for (int i = 0; i < d1.size(); i++)
            for (int j = 0; j < d2.size(); j++)
                if (abs(d1[i]-d2[j])>1) {tt=1;swap(d1[i],d1[d1.size()-1]);swap(d2[0],d2[j]);}
        d=d1+d2;
        if (!tt) cout << "No answer";else
        for (int i = 0; i < d.size(); i++)
            for (int j = 0; j < kol[d[i]-'a']; j++) cout << d[i];
        cout << "\n";
    }
    return 0;
}