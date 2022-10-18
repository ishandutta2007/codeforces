#include <cstdio>
#include <map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    char mas[7][20]={"Dracul","Troll","Anka","Hexadecimal","Snowy","Cleo","Chapay"};
    vector <string> v;
    for(int i=0;i<7;i++)
        v.push_back(mas[i]);
    sort(v.begin(),v.end());
    int n,d[9][9]={0};
    string a,b;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a >> b >> b;
        for(int j=0;j<7;j++)
            if (v[j]==a)
            {
                for(int t=0;t<7;t++)
                    if (v[t]==b)
                    {
                        d[j][t]++;
                        break;
                    }
                break;
            }
    }
    vector <int> p;
    for(int i=0;i<7;i++)
        p.push_back(i);
    int x[3]={0},best=2000000000,bkol=0;
    cin >> x[0] >> x[1] >> x[2];
    do{
        for(int i=0;i<7;i++)
        {
            for(int j=i+1;j<6;j++)
            {
                int mx=0,mn=2000000000;
                if ((int)(x[0]/(i+1))>mx) mx=(int)(x[0]/(i+1));
                if ((int)(x[1]/(j-i))>mx) mx=(int)(x[1]/(j-i));
                if ((int)(x[2]/(6-j))>mx) mx=(int)(x[2]/(6-j));
                if ((int)(x[0]/(i+1))<mn) mn=(int)(x[0]/(i+1));
                if ((int)(x[1]/(j-i))<mn) mn=(int)(x[1]/(j-i));
                if ((int)(x[2]/(6-j))<mn) mn=(int)(x[2]/(6-j));
                int kol=0;
                for(int ii=0;ii<=i;ii++)
                    for(int jj=0;jj<=i;jj++)
                        kol+=d[p[ii]][p[jj]];
                for(int ii=i+1;ii<=j;ii++)
                    for(int jj=i+1;jj<=j;jj++)
                        kol+=d[p[ii]][p[jj]];
                for(int ii=j+1;ii<=6;ii++)
                    for(int jj=j+1;jj<=6;jj++)
                        kol+=d[p[ii]][p[jj]];
                if (mx-mn<best||best==mx-mn&&kol>bkol)
                {
                    best=mx-mn,bkol=kol;
//                  cout << best << " " << bkol << endl;
                }
            }
        }
    }while(next_permutation(p.begin(),p.end()));
    cout << best << " " << bkol << endl;
    return 0;
}