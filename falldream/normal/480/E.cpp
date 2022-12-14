#include<iostream>
#include<cstdio>
#define MN 2000
using namespace std;
inline int read()
{
    int x = 0 , f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){ if(ch == '-') f = -1;  ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return x * f;
}

inline int cread()
{
    char ch = getchar();
    while(ch != '.' && ch != 'X') ch = getchar();
    return ch == '.' ? 1 : 0;
}

int n , m , q , qx[MN + 5] , ltop , qy[MN + 5] , rtop , ltail , rtail;
bool *s[MN + 5] , rev;

struct Segment_Tree{
    int ans , w;
    int *u , *d;
    Segment_Tree *l , *r;
    void init(int x)
    {
        ans = 0;
        for(int i = 1 ; i <= n ; ++i)
            u[i] = d[i] = s[i][x] , ans |= s[i][x]; 
    }
    
    void update()
    {
        ans = max ( l->ans , r->ans );
        
        int x , k = 1;
        for(int i = 1 ; i <= n ; ++i)
        {
            u[i] = l -> d[i];    
            d[i] = r -> u[i]; 
        }        
                        
        qx[ltop = 1] = qy[rtop = 1] = 1;
        ltail = rtail = 1;
        
        for ( int i = 2; i <= n ; ++i)
        {
            while(u[i] <= u[qx[ltop]] && ltop >= ltail) ltop --;
            while(d[i] <= d[qy[rtop]] && rtop >= rtail) rtop --;
            
            qx[++ ltop] = i; 
            qy[++ rtop] = i; 

            while(i - k + 1> u[qx[ltail]] + d[qy[rtail]] && i >= k) 
            {
                ++ k;
                if(qx[ltail] < k) ltail ++; 
                if(qy[rtail] < k) rtail ++;
            }
            ans = max(ans , i - k + 1);
        }
        
        for(int i = 1 ; i <= n ; ++i)
        {
            u[i] = ( l -> u[i] == l -> w) ? r -> u[i] + l -> w : l -> u[i];    
            d[i] = ( r -> d[i] == r -> w) ? l -> d[i] + r -> w : r -> d[i]; 
        }    
    }
    
    void modify(int x , int lt = 1 , int rt = m)
    {
        if(lt == rt) { init(x); return;}
        int mid = lt + rt >> 1;
        if(x <= mid) l -> modify(x , lt , mid);
        else  r -> modify(x , mid + 1, rt);
        update();
    }
    
    Segment_Tree(int  lt , int rt )
    {
        u = new int [n + 2];
        d = new int [n + 2];
        w = rt - lt + 1;
        if(lt == rt) { init(lt); return;}
        int mid = lt + rt >> 1;
        l = new Segment_Tree(lt , mid);
        r = new Segment_Tree(mid + 1 , rt);
        update(); 
    }
    
}*rt;

int main()
{
    n = read(); m = read(); q = read();
    if( n > m) swap(n , m),rev = true; 
    for(int i = 1; i <= n ; ++i)
        s[i] = new bool [m + 2]; 
    
    if(!rev)
        for(int i = 1; i <= n ; ++i)
            for(int j = 1; j <= m ; ++j)
                s[i][j] = cread();
    else 
        for(int i = 1; i <= m ; ++i)
            for(int j = 1; j<= n ; ++j)
                s[j][i] = cread();
                
    rt = new Segment_Tree(1 , m);

    for(int i = 1; i <= q ; ++i)
    {
        int x = read() , y = read();
        if(rev) swap(x , y);
        s[x][y] ^= 1;
        rt -> modify(y);
        printf("%d\n" , rt -> ans);
    }        
    return 0;
}