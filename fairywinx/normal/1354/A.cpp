// #define GLIBCXX_DEBUG

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <assert.h>
#include <iomanip>
#include <deque>
#include <map>
// #include <cmath>
#include <bitset>

#include <algorithm>
#define int long long
#define all(a) a.begin(), a.end()
#define SOLVE int t; cin >> t; while(t--) solve();

// #pragma GCC optimize("Ofast")
// #pragma optimize("O3")

using namespace std;

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	#endif
	srand(time(0));
}

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (b >= a) {
		cout << b << '\n';
		return;
	}
	if (c - d <= 0) {
		cout << -1 << '\n';
		return;
	}
	a -= b;
	cout << b + ((a + c - d - 1) / (c - d)) * c << '\n';
}

signed main() {
	setup();
	SOLVE;



	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}

/*       i52232522h2922S22222X2X2X22XXXXXXXXX9XXXXXXXXX3XXXXi
        2552232S2292922S2222232  X35iXXXXXXX9XXXXX3XXXX9XX22
      .r22S2  22222222322S9X3XXiXXXXXX  XXXX3333XX2;
      2X2222X2222XX222222222X33sssssXXXsssXXXXXX3XXXXXXXXX33XX3
     :X22222X2222222XX2222XXXXXsssss5XXsrsiXXXXX3XXXXXXXXXX9XXX
     ,222222X222XiSXX2XX2XXXXX2srrrrs2Xrrrrs5XXXX3XX3XXXXXX3XXXX,
    ;X222XXXX2XX33iX5i5XXXXXXX2rrrrrrrrrrr;rrrriXX3X3XXXXXXX3XXXXX2i
   ,2X2XXXXXXXX9SsriirsXXXXXXXXrr;;;;rr;;r;;;;;rrX3X3XXXXXXX9XXXXXX2225i.
   :X22XXXXX3XXXrrrrrrr5X2XXXXXsr;;;;;;;;;;;;;;;;;XX3XXXXXXX9XXXXX9XX5,
   2X2XXXXXX9XX2rrrr;r;;;;;;;;;rs;;;;i3hhhhh99999993XXXXXX3XXXXXXXX2s
   X2XXXXXXX9325r;;;;;;;;;;;;;;;;:::;X93hhhX5...X:s9XXXXXX9XX3XXXXXX2
  ,222XX222X5X25;;;;;;;;;;;;;::::::::r. Shh95..i::;9XXXXXX3XX3XXXXX22
  :2222XX222r;Xi::;:;r::::::::,,::,,,. X2i::,:rs,,:X2XXXXXXXXX:XXX9X2
  :222222222;;;s::::::S3;::,:,,,,,,,,,,,,,,,,,,,   X22XXXXX3XX:;229X2
  :222222222;::;:::s9h9h9r,,,,,,,,,,..........     222222XX32X::X2;32
  :2322222223;:,:99r.i999;.,,........  ...        i2222222XX22:X35  5
  ;2322222X293:,,59..3XS,.....                    22322222XX2s,333  '
  :2322222X293X,,,sr S,.......                    2322222232X:s33X
  :23X2222XX9993,....  .                  ..~     5 .2222223XX9992
  ,2X32222X999992..                 ,..'``:`     :S ,52222X232933
  :22322222939933.               .'`   , '      :S  r522223222935
   222222223299933           .:`,. -'`         r   2552229X2293
   s2232222X2X9933                            .    S555299X253i
   :X5;X2222X29933s                                55523232255
    :sr,:55593X33X32                              r5522223255
     ,S::i2529333533X                            s25X22223252
      ir,::X5299X2333;                          ' ;X552523552      , ..
            ,,:525533333X2.                 ,  ...:2555552555.,:;'      r,
              ,55552333333irr             .s ..;99r555555555s ;           :
              ,25555X333332  ,:s:      ..r .:;9999r55555555Si              ;
              :55555X3353X:       :3:....:s;;99999r555555SS:                ,
               S55555335X3:       39333sssss;99999r555555SS                  ,
               :55555X3X55X       r33ssss332;9999r3555555Si:                  ;
               ,S5555535S55    ,;   '""""'   ''''S5SSSSSSr                     :
               ,i5555525SS5.:;,                  ,SSSSSSSi                  ,:'``;
               ,i5S5555SSS5                      SSSSSSSSS            .,,-"'
               ,rS555S5SSS                    ,  SSSSSSSS       ,.;''
                :5SS555SSS     ,,  .        ,   rS5SSSSSS   :;''
                ,SSSS25SSS          :       ,   iS2SSSSSS;:'
                ,5SSSX5SSi                      iX2SSSSS                      :iSi
                ,5SSSX5SSr~.,                   SXXSSSS5                   rSSiiSS
                .5SSS35Si;   `:;-,,             SXSSSSSi               :2X2X2SSSSS
                 5SSSrXSS;         ';           5:SSSSS.       iSSiiiiiiiSS2X33333
                 iSSS 5SS;           `;        ;i.SSSS5  :iSiisissiiiiiiiiSSiSSSSS
                 rSSS :5i;             `,     : r 5SSS55isssiisiiiiiiiiiiSSSSSSSSS
               ;  SS5   S5               `';.   ,  SSS5isiisiiiiiii2XiiiSiSS2XX25S
              ,   5Si    i.                        5SSSiisiiiiiiiiii55SSSSSSSS55X3
             riiii2SXSiir::                        si5S2iiiiiiiiiiiiSXXSSSSSSSSSS5
            issssss2XSXXXX2Ssssssisi            :isiiii5SiiiiiiiiiSiSSXX35S5SS5555
           .sssssssi3XXX5iiSiiiiiisssS:         iiiiiiiiiiiiiiiiiiSiSSS2X3X5555552
           5sssssi2XX3iissiSiiiiiiiiiiii       SiiiiiiiiiiiiiiiiiSSSSSSS3332555555
         sisssiX5isiisisiii5iiiiiiiiiiiiiiiir  ri3XiiiiiiiiiiiSSSSSSSSSS55X2,.5555
         iss25isiiiiiiiiiii5iiiiiiiiiiiS3Xiii  ,XXiiiiiiiiiSiSSSSSSSSSS5S553: :255
         X2isssiiiiiiiiiiii5iiiiiiiiiiiiiiXX2  XXiiiiiiiiiiiSSSSSSSSSSSS555Xr  .S5*/