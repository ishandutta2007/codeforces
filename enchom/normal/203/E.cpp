#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct mtz
{
    bool cango;
    long long fuel;
};

bool SortIt(mtz a,mtz b)
{
    return (a.fuel<b.fuel);
}

mtz morethanzero[100002];
long long zerocango[100002];
long long morecango[100002],mcgL=0;
long long zerocangobought[100002],zcgbL=0;

int main()
{
    long long n,d,S,news;
    long long carry,fuel,distance;
    long long i;
    long long zeroscantgo=0;
    long long zcgL=0,mtzL=0;
    long long totalmtz=0;
    bool gotmtz=false;
    long long robots=0,minfuel=0;
    long long otherwayrobots=0,otherwayfuel=0;
    long long want0fuel=0;
    long long uk1,uk2;
    long long way1=0,way2=0;
    long long nofuel;
    bool jumped=false;
    
    cin>>n>>d>>S;
    for (i=1;i<=n;i++)
    {
        cin>>carry>>fuel>>distance;
        if (distance>=d && carry>0)
        {
            mcgL++;
            morecango[mcgL]=fuel;
        }
        
        if (fuel==0 && carry==0 && distance>=d)
        want0fuel++;
        if (carry==0 && distance<d)
        zeroscantgo++;
        else if (carry==0)
        {
            zcgL++;
            zerocango[zcgL]=fuel;
        }
        
        if (carry>0)
        {
            mtzL++;
            morethanzero[mtzL].fuel=fuel;
            if (distance>=d)
            morethanzero[mtzL].cango=true;
            else
            morethanzero[mtzL].cango=false;
            
            totalmtz=totalmtz+carry;
        }
    }
    news=S;
    if (mtzL>0)
    totalmtz=totalmtz-(mtzL-1);
    
    sort(morethanzero+1,morethanzero+1+mtzL,SortIt);
    sort(morecango+1,morecango+1+mcgL);
    
    for (i=1;i<=mtzL;i++)
    {
        if (morethanzero[i].cango)
        {
            if (morethanzero[i].fuel<=S)
            {
                news=news-morethanzero[i].fuel;
                minfuel=minfuel+morethanzero[i].fuel; 
                gotmtz=true;
                nofuel=morethanzero[i].fuel;
                break;
            }
        }
    }
    
    sort(zerocango+1,zerocango+1+zcgL);
    if (gotmtz)
    {
       /* if (n==1000)
        {
            cout<<mtzL<<" "<<zeroscantgo<<" "<<totalmtz<<" "<<zcgL<<" "<<want0fuel<<endl;
        }*/
        robots=robots+mtzL;
        if (totalmtz>=zeroscantgo)
        {
            totalmtz=totalmtz-zeroscantgo;
            robots=robots+zeroscantgo;
            zeroscantgo=0;
        }
        else
        {
            robots=robots+totalmtz;
            totalmtz=0;
        }
    
        if (totalmtz>=zcgL)
        {
            robots=robots+zcgL;
        }
        else
        {
            robots=robots+totalmtz;
        }
        
        uk1=1;
        uk2=1;
        while (1)
        {
            if (uk1>zcgL-totalmtz)
            break;
            
            if (zerocango[uk1]<morecango[uk2] || uk2>mcgL)
            {
                if (zerocango[uk1]<=news)
                {
                    way2++;
                    minfuel+=zerocango[uk1];
                    zcgbL++;
                    zerocangobought[zcgbL]=zerocango[uk1];
                    news-=zerocango[uk1];
                    uk1++;
                    robots++;
                }
                else
                break;
            }
            else
            {
                if (morecango[uk2]<=news)
                {
                    if (morecango[uk2]==nofuel && !jumped)
                    {
                        uk2++;
                        jumped=true;
                        continue;
                    }
                    minfuel+=morecango[uk2];
                    way1++;
                    robots++;
                    news-=morecango[uk2];
                    
                    if (zeroscantgo>0)
                    {
                        zeroscantgo--;
                    }
                    else
                    totalmtz++;
                    uk2++;
                }
                else
                break;
            }
        }
    }
    
    news=S;
    for (i=1;i<=zcgL;i++)
    {
        if (zerocango[i]<=news)
        {
            news=news-zerocango[i];
            otherwayfuel=otherwayfuel+zerocango[i];
            otherwayrobots++;
        }
    }
    
    /*if (n==1000)
    {
        cout<<way1<<" "<<way2<<endl;
    }*/
    if (!gotmtz)
    {
        cout<<otherwayrobots<<" "<<otherwayfuel<<endl;
        return 0;
    }
    if (robots>otherwayrobots)
    {
        cout<<robots<<" "<<minfuel<<endl;
    }
    else if (otherwayrobots>robots)
    {
        cout<<otherwayrobots<<" "<<otherwayfuel<<endl;
    }
    else
    {
        if (minfuel<otherwayfuel)
        {
            cout<<robots<<" "<<minfuel<<endl;
        }
        else
        {
            cout<<otherwayrobots<<" "<<otherwayfuel<<endl;
        }
    }
    return 0;
}