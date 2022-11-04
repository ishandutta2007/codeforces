#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define F first
#define S second
int _x;  char OUTBUF[10], INBUF, *IT = OUTBUF;
#define in(x)  for(x = getchar() - '0'; (INBUF = getchar()) >= '0'; x =  (x << 3) + (x << 1) + INBUF - '0');
#define out(x) do{  *IT++ = x % 10;  }  while(x /= 10);  while(IT!=OUTBUF)  putchar(*--IT + '0');  putchar('\n');

using namespace std;


const int MAXN = 101 * 1001 , SQ = 343, MOD = 1e9 + 7 ;



struct Mat{

    ll a , b , c , d ;
};

inline Mat mul(Mat& a , Mat& b )
{
    Mat ans ;
    ans.a = (a.a * b.a + a.b * b.c ) % MOD;
    ans.b = (a.a * b.b + a.b * b.d ) % MOD ;
    ans.c = (a.c * b.a + a.d * b.c ) % MOD ;
    ans.d = (a.c * b.b + a.d * b.d ) % MOD ;

    return ans ;
}

inline Mat power ( Mat& a , ll t )
{
    Mat ans , x = a ;
    ans.a = ans.d = 1 ;
    ans.b = ans.c = 0 ;
    while(t)
    {
        if(t&1)
            ans = mul(ans,x);
        t = (t>>1ll);
        x = mul(x,x);
    }
    return ans ;
}

Mat fb ;



Mat seg [ 4 * MAXN ] = {}  ;

Mat lazy[4*MAXN ] = {} ;

inline int add(int a ,int b)
{
    if(a+b>MOD)
        return a+b-MOD;
    return a+b ;
}


int a [ MAXN ] = {} ;

void build(int s , int e , int ind)
{
  //  seg[ind].a = e-s;
    lazy[ind].a = lazy[ind].d = 1 , lazy[ind].b = lazy[ind].c = 0 ;

    if(e-s<2){
//        seg[ind].a = fib(a[s]+1);
        seg[ind] = power(fb,a[s]-1);
        return ;
    }
    int mid = (s+e)/2;
    build(s,mid,2*ind);
    build(mid,e,2*ind+1);
    seg[ind].a = add(seg[2*ind].a , seg[2*ind+1].a);
    seg[ind].b = add(seg[2*ind].b , seg[2*ind+1].b);
    seg[ind].c = add(seg[2*ind].c , seg[2*ind+1].c);
    seg[ind].d = add(seg[2*ind].d , seg[2*ind+1].d);

}

void update(int l , int r , Mat& val , int s , int e , int ind  )
{
    if(l <= s && e <= r )
    {

        lazy[ind] = mul(lazy[ind],val);
        seg[ind] = mul(seg[ind],val) ;
        return ;
    }
    if(e <= l || r <= s )
        return ;

  //  shift(ind,s,e);
  //  cout<<'*'<<lazy[ind]<<endl;
    int mid = (s+e)/2;
    if(1){
        update(s,e,lazy[ind],s,mid,2*ind);
        update(s,e,lazy[ind],mid,e,2*ind+1);
        lazy[ind].a = lazy[ind].d = 1 , lazy[ind].b = lazy[ind].c = 0 ;
    }
    update(l,r,val,s,mid,2*ind);
    update(l,r,val,mid,e,2*ind+1);
    seg[ind].a = add(seg[2*ind].a , seg[2*ind+1].a);
    seg[ind].b = add(seg[2*ind].b , seg[2*ind+1].b);
    seg[ind].c = add(seg[2*ind].c , seg[2*ind+1].c);
    seg[ind].d = add(seg[2*ind].d , seg[2*ind+1].d);


}

int query(int l , int r , int s , int e , int ind )
{
    if(l <= s && e <= r )
        return seg[ind].a;
    if(e <= l || r <= s )
        return 0;

  //  shift(ind,s,e);
   int mid = (s+e)/2;
   if(1){
        update(s,e,lazy[ind],s,mid,2*ind);
        update(s,e,lazy[ind],mid,e,2*ind+1);
        lazy[ind].a = lazy[ind].d = 1 , lazy[ind].b = lazy[ind].c = 0 ;
    }
    return add(query(l,r,s,mid,2*ind),query(l,r,mid,e,2*ind+1));
}

int32_t main()
{
  //  ios::sync_with_stdio(0);cin.tie(0) ;
  //cout<<fib(6)<<endl;
    fb.a = fb.b = fb.c = 1 ;
    fb.d = 0 ;
    int n , m , x;
  //  scanf("%d%d",&n,&m);;
    in(n);
    in(m);
    for(int i = 0 ; i < n ; i ++ )
    {
      //  scanf("%d",&a[i]);
        in(a[i]);
      //  update(i,i+1,x,0,n,1);
    }
    build(0,n,1);
 //   debug(0,n,1);
    int  l , r , t;
    while(m--)
    {
        //scanf("%d%d%d",&t,&l,&r);
        in(t);
        in(l);
        in(r);
        l--;
        if(t==2)
            printf("%d\n",query(l,r,0,n,1));
        else
        {
            //scanf("%d",&x);
            in(x);
            Mat X = power(fb,x);
            update(l,r,X,0,n,1);
        }
    }





}