#include <bits/stdc++.h>
using namespace std;
#define N 40
#define K 910
int getint(){
    int x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
vector< pair<int,int> > ans;
int n , m , tag;
int a[ N ][ N ] , b[ N ][ N ] , cnt[ K ];
void init(){
    n = getint(); m = getint();
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = 1 ; j <= m ; j ++ ){
            a[ i ][ j ] = getint();
            cnt[ a[ i ][ j ] ] ++;
            if( cnt[ a[ i ][ j ] ] == 1 ) tag ++;
        }
    for( int i = 1 ; i <= n ; i ++ )
        for( int j = 1 ; j <= m ; j ++ ){
            b[ i ][ j ] = getint();
            cnt[ b[ i ][ j ] ] --;
            if( cnt[ b[ i ][ j ] ] == 0 ) tag --;
            if( cnt[ b[ i ][ j ] ] < 0 ) tag = 10000;
        }
}
void solve2(){
    if( n == 1 ){
        for( int i = 1 ; i <= m ; i++ )
            if( a[ 1 ][ i ] != b[ 1 ][ i ] ){
                for( int j = i + 1 ; j <= m ; j ++ ){
                    if( a[ 1 ][ j ] != b[ 1 ][ i ] )
                        continue;
                    bool tflag = true;
                    for( int k = i ; k < j ; k ++ )
                        if( a[ 1 ][ k ] != b[ 1 ][ k + 1 ] ){
                            tflag = false; break;
                        }
                    for( int k = j + 1 ; k <= m ; k ++ )
                        if( a[ 1 ][ k ] != b[ 1 ][ k ] ){
                            tflag = false; break;
                        }
                    if( tflag ){
                        printf( "%d\n" , j - i );
                        for( int k = j ; k >= i ; k -- )
                            printf( "1 %d\n" , k );
                        return;
                    }
                }
                break;
            }
        for( int i = m ; i >= 1 ; i -- )
            if( a[ 1 ][ i ] != b[ 1 ][ i ] ){
                for( int j = i - 1 ; j >= 1 ; j -- ){
                    if( a[ 1 ][ j ] != b[ 1 ][ i ] )
                        continue;
                    bool tflag = true;
                    for( int k = i ; k > j ; k -- )
                        if( a[ 1 ][ k ] != b[ 1 ][ k - 1 ] ){
                            tflag = false; break;
                        }
                    for( int k = j - 1 ; k >= 1 ; k -- )
                        if( a[ 1 ][ k ] != b[ 1 ][ k ] ){
                            tflag = false; break;
                        }
                    if( tflag ){
                        printf( "%d\n" , i - j );
                        for( int k = j ; k <= i ; k ++ )
                            printf( "1 %d\n" , k );
                        return;
                    }
                }
                break;
            }
        puts( "-1" );
        return;
    }else{
        for( int i = 1 ; i <= n ; i++ )
            if( a[ i ][ 1 ] != b[ i ][ 1 ] ){
                for( int j = i + 1 ; j <= n ; j ++ ){
                    if( a[ j ][ 1 ] != b[ i ][ 1 ] )
                        continue;
                    bool tflag = true;
                    for( int k = i ; k < j ; k ++ )
                        if( a[ k ][ 1 ] != b[ k + 1 ][ 1 ] ){
                            tflag = false; break;
                        }
                    for( int k = j + 1 ; k <= n ; k ++ )
                        if( a[ k ][ 1 ] != b[ k ][ 1 ] ){
                            tflag = false; break;
                        }
                    if( tflag ){
                        printf( "%d\n" , j - i );
                        for( int k = j ; k >= i ; k -- )
                            printf( "%d 1\n" , k );
                        return;
                    }
                }
            }
        for( int i = n ; i >= 1 ; i -- )
            if( a[ i ][ 1 ] != b[ i ][ 1 ] ){
                for( int j = i - 1 ; j >= 1 ; j -- ){
                    if( a[ j ][ 1 ] != b[ i ][ 1 ] )
                        continue;
                    bool tflag = true;
                    for( int k = i ; k > j ; k -- )
                        if( a[ k ][ 1 ] != b[ k - 1 ][ 1 ] ){
                            tflag = false; break;
                        }
                    for( int k = j - 1 ; k >= 1 ; k -- )
                        if( a[ k ][ 1 ] != b[ k ][ 1 ] ){
                            tflag = false; break;
                        }
                    if( tflag ){
                        printf( "%d\n" , i - j );
                        for( int k = j ; k <= i ; k ++ )
                            printf( "%d 1\n" , k );
                        return;
                    }
                }
                break;
            }
        puts( "-1" );
        return;
    }
}
int sn , sm;
void move( int ttn , int ttm ){
    while( sn != ttn && sm != ttm ){
        if( sn > ttn && sm > ttm ){
            int tswap = a[ sn ][ sm ];
            a[ sn ][ sm ] = a[ sn - 1 ][ sm - 1 ];
            a[ sn - 1 ][ sm - 1 ] = tswap;
            sn --; sm --;
        }else if( sn > ttn && sm < ttm ){
            int tswap = a[ sn ][ sm ];
            a[ sn ][ sm ] = a[ sn - 1 ][ sm + 1 ];
            a[ sn - 1 ][ sm + 1 ] = tswap;
            sn --; sm ++;
        }else if( sn < ttn && sm > ttm ){
            int tswap = a[ sn ][ sm ];
            a[ sn ][ sm ] = a[ sn + 1 ][ sm - 1 ];
            a[ sn + 1 ][ sm - 1 ] = tswap;
            sn ++; sm --;
        }else{
            int tswap = a[ sn ][ sm ];
            a[ sn ][ sm ] = a[ sn + 1 ][ sm + 1 ];
            a[ sn + 1 ][ sm + 1 ] = tswap;
            sn ++; sm ++;
        }
//        printf( "%d %d\n" , sn , sm );
        ans.push_back( make_pair( sn , sm ) );
    }
    while( sn != ttn ){
        if( sn < ttn ){
            int tswap = a[ sn ][ sm ];
            a[ sn ][ sm ] = a[ sn + 1 ][ sm ];
            a[ sn + 1 ][ sm ] = tswap;
            sn ++;
        }else{
            int tswap = a[ sn ][ sm ];
            a[ sn ][ sm ] = a[ sn - 1 ][ sm ];
            a[ sn - 1 ][ sm ] = tswap;
            sn --;
        }
//        printf( "%d %d\n" , sn , sm );
        ans.push_back( make_pair( sn , sm ) );
    }
    while( sm != ttm ){
        if( sm < ttm ){
            int tswap = a[ sn ][ sm ];
            a[ sn ][ sm ] = a[ sn ][ sm + 1 ];
            a[ sn ][ sm + 1 ] = tswap;
            sm ++;
        }else{
            int tswap = a[ sn ][ sm ];
            a[ sn ][ sm ] = a[ sn ][ sm - 1 ];
            a[ sn ][ sm - 1 ] = tswap;
            sm --;
        }
//        printf( "%d %d\n" , sn , sm );
        ans.push_back( make_pair( sn , sm ) );
    }
}
void turn( int rn ){
    for( int i = m ; i >= 1 ; i -- ){
        move( 1 , 1 );
        if( a[ rn ][ i ] == b[ rn ][ i ] )
            continue;
        int xn = 0 , xm;
        for( int j = rn ; j >= 1 ; j -- ){
            for( int k = (j == rn ? i-1 :m) ; k >= 1 ; k -- )if( a[ j ][ k ] == b[ rn ][ i ] ){
                xn = j; xm = k; break;
            }
            if( xn ) break;
        }
        if( xm > i && xn < rn ){
            while( xm > i && xn < rn && xm - i > rn - xn ){
                if( xn == 1 ){
                    move( xn , xm - 1 );
                    move( xn + 1 , xm - 1 );
                    move( xn , xm );
                    xn ++; xm --;
                }else{
                    move( xn - 1 , xm );
                    move( xn , xm - 1 );
                    move( xn , xm );
                    xm --;
                }
            }
        }
        while( xn != rn && xm != i ){
            if( xm < i ){
                if( xn == 1 ){
                    move( xn , xm - 1 );
                    move( xn + 1 , xm );
                    move( xn + 1 , xm + 1 );
                    move( xn , xm );
                    xn ++; xm ++;
                }else{
                    move( xn - 1 , xm + 1 );
                    move( xn + 1 , xm + 1 );
                    move( xn , xm );
                    xn ++; xm ++;
                }
            }else{
                if( xn == 1 ){
                    move( xn , xm - 1 );
                    move( xn + 1 , xm - 1 );
                    move( xn , xm );
                    xn ++; xm --;
                }else{
                    move( xn - 1 , xm - 1 );
                    move( xn + 1 , xm - 1 );
                    move( xn , xm );
                    xn ++; xm --;
                }
            }
        }
        while( xn != rn ){
            if( xn == 1 ){
                move( xn , xm - 1 );
                move( xn + 1 , xm );
                move( xn , xm );
                xn ++;
            }else{
                move( xn - 1 , xm );
                if( xm == 1 ) move( xn , xm + 1 );
                else move( xn , xm - 1 );
                move( xn + 1 , xm );
                move( xn , xm );
                xn ++;
            }
        }
        while( xm != i ){
assert( xn - 1 >= 1 && xm + 1 <= m );
            move( xn - 1 , xm );
            move( xn , xm + 1 );
            move( xn , xm );
            xm ++;
        }
    }
}
void turn2(){
    for( int j = m ; j >= 1 ; j -- )
        for( int i = 2 ; i >= 1 ; i -- ){
            move( 1 , 1 );
            if( a[ i ][ j ] == b[ i ][ j ] )
                continue;
            int xn = 0 , xm;
            for( int k = j ; k >= 1 ; k -- ){
                for( int l = (k==j? i - 1 : 2) ; l >= 1 ; l -- ){
                    if( a[ l ][ k ] == b[ i ][ j ] ){
                        xn = l; xm = k; break;
                    }
                }
                if( xn ) break;
            }
            while( xn != i && xm != j ){
                if( xn < i ){
                    move( xn + 1 , xm - 1 );
                    move( xn + 1 , xm + 1 );
                    move( xn , xm );
                    xn ++; xm ++;
                }else{
                    move( xn - 1 , xm + 1 );
                    move( xn , xm );
                    xn --; xm ++;
                }
            }
            while( xn != i ){
                if( xn < i ){
                    move( xn , xm - 1 );
                    move( xn + 1 , xm );
                    move( xn , xm );
                    xn ++;
                }else{
                    move( xn - 1 , xm );
                    move( xn , xm );
                    xn --;
                }
            }
            while( xm != j ){
                if( xn != 1 ){
                    move( xn - 1 , xm );
                    move( xn , xm + 1 );
                    move( xn , xm );
                    xm ++;
                }else{
                    move( xn , xm - 1 );
                    move( xn + 1 , xm );
                    move( xn , xm + 1 );
                    move( xn , xm );
                    xm ++;
                }
            }
        }
}
void solve3(){
    for( int i = 1 ; i <= n ; i ++ ){
        for( int j = 1 ; j <= m ; j ++ )
            if( a[ i ][ j ] == b[ 1 ][ 1 ] ){
                sn = i; sm = j;
                break;
            }
        if( sn ) break;
    }
    int an = sn , am = sm;
    move( 1 , 1 );
//    printf( "%d %d\n" , sn , sm );
    for( int i = n ; i > 2 ; i -- )
        turn( i );
    turn2();
    printf( "%d\n" , (int)ans.size() );
    printf( "%d %d\n" , an , am );
    for( int i = 0 ; i < (int)ans.size() ; i ++ )
        printf( "%d %d\n" , ans[ i ].first , ans[ i ].second );
}
void solve(){
    if( tag != 0 ){
        puts( "-1" );
        return;
    }
    if( n == 1 || m == 1 ) solve2();
    else solve3();
}
int main(){
    init();
    solve();
}