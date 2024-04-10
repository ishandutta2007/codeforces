#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int n,bl[2],el[2],br[2],er[2],ansa[2][2],ansb[2][2];
signed main()
{
    cin>>n;
    for(register int i=16;~i;--i)
    {
        int pos=el[1]+(1<<i);
        if(pos>n)
            continue;
        cout<<"? 1 1 "<<pos<<" "<<n<<endl;
        int x;
        cin>>x;
        if(x<2)
            el[1]=pos;
    }
    //cout<<"% "<<el[1]+1<<endl;
    for(register int i=16;~i;--i)
    {
        int pos=el[0]+(1<<i);
        if(pos>n)
            continue;
        cout<<"? 1 1 "<<pos<<" "<<n<<endl;
        int x;
        cin>>x;
        if(x<1)
            el[0]=pos;
    }
    //cout<<"% "<<el[0]+1<<endl;
    bl[0]=bl[1]=n+1;
    for(register int i=16;~i;--i)
    {
        int pos=bl[1]-(1<<i);
        if(pos<1)
            continue;
        cout<<"? "<<pos<<" 1 "<<n<<" "<<n<<endl;
        int x;
        cin>>x;
        if(x<2)
            bl[1]=pos;
    }
    //cout<<"% "<<bl[1]-1<<endl;
    for(register int i=16;~i;--i)
    {
        int pos=bl[0]-(1<<i);
        if(pos<1)
            continue;
        cout<<"? "<<pos<<" 1 "<<n<<" "<<n<<endl;
        int x;
        cin>>x;
        if(x<1)
            bl[0]=pos;
    }
    //cout<<"% "<<bl[0]-1<<endl;
    for(register int i=16;~i;--i)
    {
        int pos=er[1]+(1<<i);
        if(pos>n)
            continue;
        cout<<"? 1 1 "<<n<<" "<<pos<<endl;
        int x;
        cin>>x;
        if(x<2)
            er[1]=pos;
    }
    //cout<<"% "<<er[1]+1<<endl;
    for(register int i=16;~i;--i)
    {
        int pos=er[0]+(1<<i);
        if(pos>n)
            continue;
        cout<<"? 1 1 "<<n<<" "<<pos<<endl;
        int x;
        cin>>x;
        if(x<1)
            er[0]=pos;
    }
    //cout<<"% "<<er[0]+1<<endl;
    br[0]=br[1]=n+1;
    for(register int i=16;~i;--i)
    {
        int pos=br[1]-(1<<i);
        if(pos<1)
            continue;
        cout<<"? 1 "<<pos<<" "<<n<<" "<<n<<endl;
        int x;
        cin>>x;
        if(x<2)
            br[1]=pos;
    }
    //cout<<"% "<<br[1]-1<<endl;
    for(register int i=16;~i;--i)
    {
        int pos=br[0]-(1<<i);
        if(pos<1)
            continue;
        cout<<"? 1 "<<pos<<" "<<n<<" "<<n<<endl;
        int x;
        cin>>x;
        if(x<1)
            br[0]=pos;
    }
    //cout<<"% "<<br[0]-1<<endl;
    --bl[0],--bl[1],--br[0],--br[1],++el[0],++el[1],++er[0],++er[1];
    //cout<<bl[0]<<" "<<bl[1]<<" "<<el[0]<<" "<<el[1]<<" "<<br[0]<<" "<<br[1]<<" "<<er[0]<<" "<<er[1]<<endl;
    ansa[0][0]=1,ansa[0][1]=n,ansa[1][0]=1,ansa[1][1]=n,ansb[0][0]=1,ansb[0][1]=n,ansb[1][0]=1,ansb[1][1]=n;
    for(register int i=0;i<16;++i)
    {
        int x,y;
        if(bl[i&1]>el[i>>2&1])
            continue;
        if(br[i>>1&1]>er[i>>3&1])
            continue;
        if(bl[i&1^1]>el[i>>2^1])
            continue;
        if(br[i>>1&1^1]>er[i>>3&1^1])
            continue;
        int a11=min(bl[i&1],el[i>>2&1]),b11=min(br[i>>1&1],er[i>>3&1]),a12=max(bl[i&1],el[i>>2&1]),b12=max(br[i>>1&1],er[i>>3&1]),a21=min(bl[i&1^1],el[i>>2&1^1]),b21=min(br[i>>1&1^1],er[i>>3&1^1]),a22=max(bl[i&1^1],el[i>>2&1^1]),b22=max(br[i>>1&1^1],er[i>>3&1^1]);
        if(a12>=a21&&b12>=b21&&a22>=a11&&b22>=b11)
            continue;
        cout<<"? "<<a11<<" "<<b11<<" "<<a12<<" "<<b12<<endl;
        cin>>x;
        cout<<"? "<<a21<<" "<<b21<<" "<<a22<<" "<<b22<<endl;
        cin>>y;
        if(x==1&&y==1)
        {
            if((a12-a11+1)*(b12-b11+1)+(a22-a21+1)*(b22-b21+1)<=(ansa[0][1]-ansa[0][0]+1)*(ansb[0][1]-ansb[0][0]+1)+(ansa[1][1]-ansa[1][0]+1)*(ansb[1][1]-ansb[1][0]+1))
            {
                ansa[0][0]=a11;
                ansb[0][0]=b11;
                ansa[0][1]=a12;
                ansb[0][1]=b12;
                ansa[1][0]=a21;
                ansb[1][0]=b21;
                ansa[1][1]=a22;
                ansb[1][1]=b22;
            }
        }
    }
    cout<<"! "<<ansa[0][0]<<" "<<ansb[0][0]<<" "<<ansa[0][1]<<" "<<ansb[0][1]<<" "<<ansa[1][0]<<" "<<ansb[1][0]<<" "<<ansa[1][1]<<" "<<ansb[1][1]<<endl;
    return 0;
}