#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll x,Lx,Tx,y,Ly,Ty,i,j,a[101010],b[101010],c[101010],sel,hey,vero,has,nica;
ll fpb(ll aa,ll bb)
{
    if(bb==0)return aa;
    else return fpb(bb,aa%bb);
}
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

       // x=rand()%100; Lx=rand()%50+x;Tx=rand()%50+Lx+1;
       // y=rand()%100; Ly=rand()%50+y;Ty=rand()%50+Ly+1;
        cin>>x>>Lx>>Tx;
        Lx=(Lx-x+1);
        cin>>y>>Ly>>Ty;
        Ly=(Ly-y+1);
        if(Lx==Tx){cout<<Ly<<"\n";return 0;}
        if(Ly==Ty){cout<<Lx<<"\n";return 0;}
    //    cout<<heyo()<<"\n";
       // for(i=0;i<=78;i++)cout<<a[i];cout<<"\n";
       // for(i=0;i<=78;i++)cout<<b[i];cout<<"\n";
        hey=fpb(Tx,Ty);
        has=0;
        if(x>y)
        {
            sel=x-y;
            vero=sel%hey;
            has=max(has,Ly-vero);
            nica=vero-hey+Lx;
            //cout<<has<<"\n";
            //cout<<nica<<"\n";
            if(nica>=0)has=max(has,min(Ly,nica));

            sel=(y-x+Tx);
          //  cout<<sel<<" "<<has<<"\n";
            vero=sel%hey;
            has=max(has,Lx-vero);
            nica=vero-hey+Ly;
            if(nica>=0)has=max(has,min(Lx,nica));
            //cout<<nica<<"\n";
        }
        else
        {
            sel=y-x;
            vero=sel%hey;
            has=max(has,Lx-vero);
            nica=vero-hey+Ly;
            //cout<<nica<<"\n";
            if(nica>=0)has=max(has,min(Lx,nica));
            sel=(x-y+Ty);
            //cout<<sel<<"\n";
            vero=sel%hey;
            has=max(has,Ly-vero);
            nica=vero-hey+Lx;
            //cout<<sel<<" "<<vero<<" "<<nica<<"\n";
            if(nica>=0)has=max(has,min(Ly,nica));
        }
        has=min(has,min(Lx,Ly));
        cout<<has<<"\n";
}