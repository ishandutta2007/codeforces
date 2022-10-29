#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using namespace std;
bool cmp(pair<int,int> a, pair < int , int > b)
{
    return a.first<b.first;
}
int main()
{
    char a[8][8];
    vector <pair<int,int> > w,b;
    int i,j,mw=10,mb=10,f,l,k;
    for(i=0;i<8;++i)
    cin>>a[i];
    for(i=0;i<8;++i)
        for(j=0;j<8;j++)
    {
        if(a[i][j]=='W') w.pb(mp(j,i));
        if(a[i][j]=='B') b.pb(mp(j,i));
    }
    for(i=0;i<w.size();++i)
    {
        f=0;
        for(j=0;j<b.size();++j)
            if(b[j].first==w[i].first && b[j].second<w[i].second)
       {
           b.erase(b.begin()+j);
           j--;
           f=1;
        }
        if(f)
        {
            l=w[i].first;k=i;
            while(i<w.size()) {if(w[i].first==l) w.erase(w.begin()+i); else i++;}
            i=k;i--;
        }
    }
    mw=10;mb=10;
    for(i=0;i<w.size();++i)
      mw=min(mw,w[i].second);
    for(i=0;i<b.size();++i)
      mb=min(mb,7-b[i].second);
    if(mw<=mb) cout<<'A';
    else cout<<'B';
    return 0;
}