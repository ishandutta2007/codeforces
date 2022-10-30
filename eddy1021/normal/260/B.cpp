#include <stdio.h>
#include <string.h>
#define L 100010
int cnt[40][15][5],ad,am,ay,l,max,td,tm,ty;
int md[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char c[L];
bool id( char tmp ){ return tmp>='0'&&tmp<='9'; }
int main(){
	scanf("%s",c); l = strlen(c);
	for( int i=0;i<=l-10;i++ )
		if( c[i+2]=='-' && c[i+5]=='-' )
			if( id(c[i]) && id(c[i+1]) && id(c[i+3]) && id(c[i+4])
				&& id(c[i+6]) && id(c[i+7]) && id(c[i+8]) && id(c[i+9]) ){
			td = ( c[i]-'0' )*10 + ( c[i+1]-'0' );
			tm = ( c[i+3]-'0' )*10 + ( c[i+4]-'0' );
			ty = ( c[i+6]-'0' )*1000 + ( c[i+7]-'0' )*100 + ( c[i+8]-'0' )*10 + ( c[i+9]-'0' );
			if( ty>=2013 && ty<=2015 && tm>0 && tm<13 && td>0 && td<=md[tm] ){
				cnt[td][tm][ty-2012]++;
				if( cnt[td][tm][ty-2012]>max ){
					max = cnt[td][tm][ty-2012];
					ad = td; am = tm; ay = ty;
				}
			}
		}
	printf("%02d-%02d-%d\n",ad,am,ay);
}