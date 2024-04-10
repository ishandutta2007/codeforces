// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define mod7 1000000007LL
inline LL getint(){
  LL _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline LL add( LL _x , LL _y , LL _mod = mod7 ){
  _x += _y;
  return _x >= _mod ? _x - _mod : _x;
}
inline LL sub( LL _x , LL _y , LL _mod = mod7 ){
  _x -= _y;
  return _x < 0 ? _x + _mod : _x;
}
inline LL mul( LL _x , LL _y , LL _mod = mod7 ){
  _x *= _y;
  return _x >= _mod ? _x % _mod : _x;
}
LL mypow( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 1LL;
  LL _ret = mypow( mul( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = mul( _ret , _a , _mod );
  return _ret;
}
#define N 702
int dp[ N ][ 10 ];
int fac[ N + N ] , inv[ N + N ];
inline int C( int a , int b ){
  return mul( fac[ a ] , mul( inv[ b ] , inv[ a - b ] ) );
}
int pp[ N ] , ten[ N + N ];
int sv[ N ][ 10 ][ N ];
int sv2[ N ][ 10 ][ N ];
int iten[ N + N ];
int dpw[ 10 ][ N ];
string magic;
char encode( int vl ){
  if( vl < 10 ) return vl + '0';
  vl -= 10;
  if( vl < 26 ) return vl + 'A';
  vl -= 26;
  if( vl < 26 ) return vl + 'a';
  vl -= 26;
  return "!?"[ vl ];
}
int decode( char ctmp ){
  if( isdigit( ctmp ) ) return ctmp - '0';
  if( isupper( ctmp ) ) return ctmp - 'A' + 10;
  if( islower( ctmp ) ) return ctmp - 'a' + 36;
  return ctmp == '!' ? 62 : 63;
}
void build(){
  magic="0000100002000030000400005000060000700008000090002j0004s0006R0007S0007v0007o000770005u00045005V3008pk00AKp00AP4009NJ007cI005Sp003He001RZ09vmP0EGDk0EnkB0CxYS09vrj06djg03lAV01f6u00TO1GnbxpLfRv!JsjgZF7Ac49s6ox5RSAo2QhVx0nzYe0946ZIzKQstH1b7W5Gc!EHZRU6rJ97a6dJUb0150N2VHu2lfgvufytUfizrAQt6vx2ye7IeKNSEFL5LjKMMcABtlQRqhi?x2f4XfA2fPk2Dobcr!Jy8HP4ZgP8yO14wX05hNBHuqgXcnqJaV3wq0WRc0Ev9fvYKD6UOtqGbKYgdd69OEDNdae?MQi5YnqMTzlUbfPgVoBgX?hj2koODofrvkV1D9AWn743ybmgoQ8wFRf7hqIloCUsBcw9TLNu1eJGPmCPcRRRujvjFOWgXJ3lvRYFcNeuVe0ZIgmHImEBacIHE4OXatNi9phohrsuaxa7v9Lv3V!GPgolVWZKhRZI5tmd4CZo5G?MDnqMD?A0ixIq6BLLJKWbTmHASLVqOolv02I0hUVMo8?4MBiSTnCBMrwHpyN1VJl65?uvSH?8h3Bkvb7Bs1sKAZGdAVjNh3q!abuLEgl?hHxbvxvLqRwQEbhLC69HMC6mELEtwEPswAeZFZrkYzECogGtE1yXKUIz0uz?CGLFZEUaj0dCE1jyMYFjcplMbX1Gy2A3n?V9dl9Fn0BItFaA5llbFnhXoUtpivoFBailMzsRRIofkPF0RJZL14lDVYfUOSwmGsRIJ3pSy0su!anb5lvtHgxJ6w0NchGpp7i0sm0uv9VDsxHyfMEUrRenW2WedndVssdR9Hffljjqs7a!zSVmBFB2uoPp7u9kJR!LqgLn21mgAfTMzzyjUuqEhELXV5YE!zOxKFhEfgSkiEu30zP69UEUUOac5c5lsqkcIOwSUPBSzYNHexATBCHal6MoShRqfjRFgrruZmA?746Z8QbaMxdr5reVRYrWMoOAYczHTVKbVBEVgfmAFUKtfP7bdM8GS7LfRIU?c2trU?j8!!oEuu9vtcD2NyikGTVqs9We6??3MiFaEX840YQuibyyTJq86V?oKPppuVBdj9eFfkzJ2aNnv2wCjFgTPcc232G2WGPYN6Hc??RpkeZGj6zQLEjr33aD82noNmyhWugLSY5wNMrzdUN3mvuUL8VFUMcTIU0AtwjObmyux7nySOZDNrtvH8cq199N1zW!SvGssqCBiZp9oYrLtCh?PbLUz?uI7EjamFiHW5QPsgY9RqVu?waqezOO8bhMIxYhAKeZLfQWCyL1ictTQIwpi?HfR1G2bqzMkJIZ0JuIBZLlmJbgumteQ?jURV2iCRATTq?vGTwNO5xcthQ!?kRktMHpRrVxvklJdA05tLAz4wAKLV3rgLrbApy2m4Vm2Zlivgegm!cXa4jN?ghP?lKu4BSeb70l!w1fQmscZyv21w7CSTOK!nv9a?i9HNl12PoK1u14IxBYZwK70UVSn62gkKATzM23mVuQ?NNLXSsxeol?QOSdt9irrqOMFGWSJgrDv3p4DH6hY5i35GiFFFAgOA73BAnLxDwXIuKmhBNoIihcoDCZebb8mwz7e0os40R6l47NFcvsYbhDtO!35X924EeFRnA0B5Pz7!KKWURelGcpfgAb?z5m0MW7hNm1wbdQeT3tNcQY3QsHBsYm9xixR8a01SbI1aViXWxb4AOsVuSuj?trT6kwQ6fs6o40h5NaiSwGDwGsG3Nd!UqJtDaOnT!oiw8aXjAGA6K5?6uInKxmJO6OlB!do!xIlKJoCN5opbPCA808c4ncowvXlLWGNkhQ6Ce7owBaY2?OTnkCdrGeQQVrms9uJOK2MvTpLitIGtlrDKqOANsesNskFYma?wPgmEskrfHf0WPh5!Rku0SsKN5MT2l6LLsotlGQWCtcdpDh6WQYmgNUxWSkxdoYP32ccIUPcketGYN?!BeCmkkbjWWFLkCEWYkVX7aYCl2S4Y7nSoZRQ5T9zuK6RakJRbV2EWdTZ?i2?i8ethupl10kaIixjOnqY9mbZbcbH8zwOVvX4rBROrAe4eCXs47LTzlsusIhdQ?Ku8e5?!zlfCkJjqGl18dQR!DakXyAkzpW0srZIBWz7oQycD8a2O7v86FWu4sq1As7CzjHh4ooBFZTtlAy7zedYy74cF4tBkJgSGHS3csUkb5D8hmYksbMt98IXAWh6PfF25zIKD!uNSf07e5ZZ3dXEvPjXkmEyE3M9edyIb7iLdH4J2iKRAsEFiQ8Uf?DbOuT3f1l3a1Mv74fN0rtJHUhQhtAGo8ipLnLdPEGgUDTNz4vkSdGyUtcEY8O8OyqR?Uj?RKoEgYDs2KPUElxlbRmd39VeQM60vIh!OWVeB7e5pYXjkw7RbFTPquB7Crk2vglJOTNFCqvY6nPQyoVDlY20yRoReuQDDnRk??OoIEyUI8ucU0AOfCOQQqxXoBtkRIipYnxHAuAQvFv1azbw0skOTtFj6ec71Zs66nE7GcqACP8EXSh2?tPVnPyVgckaf9T?th?JlkdRIbgxvi8zP8ij99GBL6m9kTJA0Ozugmbd06R8?AZnCUd!ErB9zrq4?1A0DVMjxMD!a5HFPvTxSPuxBXPiiedIFCtXWGR2whCpmvBrIVC!Rd6pSjiJzvJegsCswcwEc47LU68YRbl78iVKucAC1RZuMbBd6SCEDgZY95AWQ0FDGuh0QtdpyrS8Ob7KAdWH!nDbEhEizcFXS6?E616JqX4zPsTmBZU6rgVOFGSwN1aHDvFTrFx9KfXYKGaCNlLlY9ql525iKwo?QwnEIEFYovTqloXnSfZb0TcuG0Okgpjak3NCp7EZ8ZQDekIAxN8Bosk1LIw4dQWDcVfvj7rOSe?U7iFYQ6FIgiWZgZ8KMhRJcRZHUTQxjP0LMkwGFa8Nr!16p9OfR4gSyfGvc8SoF7RL?PF3OpP3dglTITO1ulxkn3TkOUWr1Fml3PtXEMWPEeYNi06bcwZTVMRcjpp?jfXAd5idUEleG?90BgNDfN10wHFBf6llgCa5ju2Krm6vmyXlUriC4XbCIfRTfDKd7mQpfT!A6O3KKzqbNtqROshHc22qNp5OkopoGSGzb1OrKDkeHdrJdjkzwAEredPV59wKtip3VBhSWStMiGgM?2VeIOKk8ZzYnqbZri1lM0eHYw7L1zYlZoL!5D0CzH0sSDs57CKGCkZotUfek!iu?r1AelPe7O2j3Wh9U422yahe6xh?K5JXXALUr3hOh0FjTneGxMLRMD9IL2yDRWD0JBhl6IeKP5wrp1H29GUX4OxOqGhHtEv2OIcg4kcwGsotpYMgHOmr3vO2qYyUXoNYl1IoyI3rCwvPRIFYYtOCjUzBqn50NVGQ5rA52eFfxZvUWMDWC9WBeZQke??aTrlDvxvxehtxOAW9iQP0OrHmBbjYOaPDv6MHSqu4zEPXNoHH3NDBfhPniTWsstw0hsWdilnhBQmCpUzFYaY0azNVyOzuL!JdieZ0?NfiRQ1di37Bh8sfohM8vEg7Qk1or0bNJl6Al?3Lr4lgcEL9OHz2n1M53CBpf14PoaD0JCVqDz14c4po5Nw0c3UJq014zRJLp3TOdJ2CfTwGx2qeWoL9Z!9izVg7H1t8irQvIRqg4C!nKZmCDwVovz1u5T84UHeWCL!Ih0IpyifFwYimWQ3GwDWBBMaIlrTAoY6YXNnyr4XbgEatKCYkfDzYeJO??EclpDlCKEq8sexFgrmasR8qn!rGnzy79VVFf9tIQaEiiDBCSAU8q85Oo6yirSX8FxnFA!27HUByLn9ODSxwzGCNTVd1Jx3Bfu2LOj2vLz78J2rQnDFl7naUbgWD6xgufsu72e5s3ggcAalKN6AUqox5H2nk4KsE72rFLXOWB43R6tBEi4LirW?oAQOTl5nTDiAxUqacok9qKrsSzLvBIuisnHbHw9y2WRGW0kgwX347eEXROHrrctdkAYNU?532a4OGCUFzJEMoFXkMFYkfrlcJb5iUp4vynNRCAhz5uBxOSQdLKFD3e5rY!yAqIzIkwsUmzW17P2NR28e7Hz0WEu6t73scPIhvwzGdFDfGGxMKSdDG9U7DkEFL5JrczugMivkzDY77UNu0gDnVyNk6WSqXKjsjkgQJYKgWarkdMfKDjVZ8J2MX3CGZowfn!WtREXGpAWwPFYooysvXYkvzTbjCtTCMVo9JSc78ZNokT9nneKrzN1IxApA235HdPij94EUjn6JwXSbHshYxk6RBshi0rG5NiG77tpNFv8g0C6NMnA?Ouq6w9dtRsnsL!WMwBY?AxM7U4pARlw5Zt3xp1VrsOoyA?noDHN9aUkRIpvcEiL3iJ4LHtY0mWWym50p9NKi3cUH5O78JNFyro!drBqicIVK1ycJLfWZGJfuDbxHYvvVkmOQm1WBwMR!VqvQhzVm2YCvS68IEXVqNYIlvdVOOePy0rTmLMyPbhBVXopYFBK9ddFBrVcB9iO1CaoUdjp6NSzqRNcGKkRNrHQ48oxzEr9VIS7VIZNAKgAioeMB4!P2OL0fM1ClFrblhjyoMZAJ4oGl2Wn!9Yra2QCYwWpnxffyg0Y6bBOhngrOHAGhFkeYY3E1uszB?2?RMSPWLcUhKKP3ImhWkKs1JrTzUtsHLamDyAzO9jFjcng6poCbwNIeojnJaKCfjo7mgik3Bwq4qOom9csXh6HWyBMLoq9veI3kc?EhmXA1eJh5V90EfagZLj?ahBKICU3T!ZIVaabAVU5JOP6vDccgHH3wHdlvt94u481ZdV1bm1gzszgJCcPR57BCx9Ji1xxZVIoeZLTY7C7cZnd4yeRVfsIAXA3gdp7TVMQSG04VGbFIfr?6lxHjK88iiDHoJG!SdsycSXdQfYoIQMmSoJIHPQb4hwH11kSgoCsPwFSDWANzGrGhu15Q4tW96f9WfAradhVojazOPx9FrIKsicA5rbNwkuc0em1bl6b6Qom5MsENHmr?bUl7O5hXeZaY1bnclhtQXNqRb8ToM4xpfXJVfnZmvcC6nbS3UXPOkN4042HRycJVGg56O0?c6yPuiLNrNO4AVundryr?1EsV899070nyXqeoHftkvnH8BNDlvtiqH8RxJHIrbGRvjU9bWssfbg8vmCp!flQl?koxXQ4JcdH8phKhsNT7MPGdQylFhhC5PxQdpVY2eAcgoPan5PsBs1or263mbivPVwBvurkINksW0fUXiJ?DYilxaucgsoGkFmumQtMgi1kOFi32OAL6ihaW9XNuZmlF9Uo8oAQLcmNf9vIxq6YkX16QU35kgkSmdtu66KvdjaB67qGw7AclcEdnzRlUz2YAOqIBV2CJVrMPKf8jAkuGCkJGcWvghEypsLYB21KpJDZwR5qm0XuCAZIMgdcxX4DgCm0AlZBtPwnY!VM12X3CKSLLYDH2PbIBy7W1FtzGJIz6zBzCu8ucUe!bf8y?YI!s?wa78YlCgQWKEOMQY7VL6Pmx8lYDvQY9ZmyGRC74aMHJJWhE7V8Pm09CvdrKcOTpEqa6kFfEE15WbNuRAROQrDUMAfJfTx8jv0SwIA2m2H2E0VkYBYokhsYz6aVxFysVkHbk9GYsU7NTcCWbluRLzxxZJ?O9NKK992b1BXCh9uoYSpGDglCCH14W?GNx3hlccYFcRe7bQeU!NDNdt!sPWztTjbl4JfhzjIuc?zqtQa1oSOu!7jAZgVpJ36bG2pyxVdN8CRnBxf2zfpOGpmkoYVxXDTasIscUP2JVOcw?l3x?uxEwdcwrg?PXEoaujwywBRvogtjk8oeXVkRkkiWpCNzF?b5FLePWiFOfh2eRUvf!jlr4miQoX8JogKbkqvhYyeVQKP8AI6sHagbW?0hSFfODDS3jb12FLpG9MMb0VserxWxcs5XX8UbRL7Z3EE7jJPWD7SC1KnPSbMPQPmhoZ5xqkzyB8ygdGUlitlfS33qYzFVhbdO8IcuOTTdU!762yjU?hs7SyEdJ69AIDhHIPtYfQ60gN7sgBl1ZKPiBwavzoKCSStmqqfoL53?nAx8nd6bspFnLDcecva0GmmDrUcCz9JD77AOAuY6kgOzRpSYWNXrZHJTTf2GZt8uqh?PkMM65nnsjf0W1S!b6nb8AoRGvjadrSeM3lkEOJm7DG2HfBlTztnj4WqjdVf!XIa7Cj4WDDZtNzphtrs!7ZjcL2F0NBtjw!xMLqZzC2wA5pDVwlpwEGh08Ktz3OFn9!5ZSxJ6NopGzenA07PWYOSpwV2FFYOVpjcCDRX2G?6wsA8QHynRUTMUQ6OahHToW7i6N3ycCDQue3pF4KihvFBXLwLJMmCqQNj6JmEui0FXOJi4yVJQmn1UKi6KjfeFj0yZw4g?l9jaRgxYvpQNAnyj561woU9XTiFoLJbo3IYzxgnEOLPR3ZDx619UYzEroPabI2Vj0jYP5TwG0IhrEXkbLAuPSfgSRUuWbbiOMblb2PjxA7NBLGWHHev9u9VtsfZoXIPhuCCGlFtjM1VhuvToXXIALFbyLWZBz6DWY5r104RlbefTDJqfxLj!RQUtrFJuwncY39W5agSva0mcGY!aPokLnhcGEpSiN7u!EAvPq4hFIQ3rsN5LjvWclokgQ!66o1n?L2StvLk3!0MT6NvFvKlCwcYwLnG8QmF57jke50D2JAvG?t9BwHu7AlGFWlvuzhWMXEbfamIhIEP2enSxyoI7QwbtcsXOgOrZVOOWZAL?9Yky3xdoI!NM2w8bj0HralnxeuSbpymUDgaOcjr61PcDUwGgcNV0g1As3qza5ofIBsnGVeBcIm5ztEPbfK2rrP7av?VzKSeB54IEk7jht6lvU9j0VF2KwO8wppB93!UBHyys98XkXEx!pNIkGQkekJhGe4V2CmG6oEA7ejPpWJUtVzodLleGgLVDwdWLxJSUcHbxmxPZcvuot3TlTD35UZfdLV6Wlt3ZcsDZSG8Yh4Q1ktezbND5rrt7roar7epf26UzeJCzJpOrwRY4g96tCuENvBkZ?mUFegN7XGaTXVXrHlup2KoayCsmrJOliKfKlDq4EMPkasAd5!tkBXFOKEmUoVwETImpSBVhH4cH?23i1?XohTIbKQAx0YxhPDa9YxuCtVpRXKCKlUGAiBJNrHg2GMG1qeakx9OKUCQp2PFJMFHcWkVv62KjviKBXhjjnxemo9pY?FR65!oLZCPVyMRlMwP9W987L!S3TZ?rGhkWV3m7SCJe6i9g3WcRgEPLDdDfYZTrCzCSI!iCCz?rqV2!fAh6VXvDIIUA5Gno1UabZjHWWgWnS58gRT!yfLf0!0YLTbBEf77KzHxNM5ffAK54FkSYd!C7VEmqliFgBweE3Qvk1ygQDarOspJ09rZDjEJS4c8Ip4eZajqgfoq29?Pb4HRhD8cwvCO7kLEzIIvReh6mMn0U14JvLMX275u3H9VpPaG3rTESCGAe8ku7jf4M?g41SsiQnxbSYMfMymU5fIF!R9w4YVHwuKWucjRa5Io80ioNZ2uGyDtHSLvL6FycJrQrFDdeKUW84yVRtVGdsMvyMU39uhrsqrbU9GFsDeiYAPNwMJppIUC8ZJWJhkPLbU!qJcpR5Vo6jZoN18XSsZ2dh5v44dxk1ImN05TQvQQ65Rj!eFEszPRpw00AO2yNWuYokeTs!lgvmeRoCi6AYMRu5?InCGI0XsJ7FCpyHNu?AawZXiUQ75mEm8pVJb0bUOeMuA4ncV8bkWN4xNDBseIv7ykXMbqtdsiIp9JF!PnqWTXcG5BBJKgS!lmHVIR5ZJQ4b?oj3IXJ1XgEJg4vAMcOAa0QUrYBLNlDIKGaSy7!FcY8FKY!IJSM8gt4PbUFi?A?3eML6bks5Rt8ZzlKkq9fogDFlt5VF5IsUyt6QHbgLUzH4wWB?Ii8Y0zrp4ahMs0HQM4GU0vXyAR38a0xnuq4GBnWoqHElf?Pn86pjKp1vgrKN?iS11hsdJ2uiqOfCco6YTJspNdSKEBBpg70OVcaSqG5SnRxfDt38606tUITsd1RsVC!Aew?tKQ3RLqyVTSHZweuTPh6iijYS2Ds6PLhvo6G7Sl5O3?oCYa4cQYVX7zbNDMuU9r!pl51IEQCQFFqXMMVO4uf3BPpAS1Hx6rGXYc1Vocb12qtApjs6OHq7nYLRxFnY85qlHZdsLxFAPTbqokt8WK5y!NrqkPDp7phsc8w7lo1lJqavi8J1tjUMDHxOqjj!TZGSuBY75oeyxaz5g2ekDIw4goj4rECSOk617diWx1VNFvBGHZBCxROaknk!WJt0o9Mte2W?0vvfZQeBifjtuF7VG7IQedULRR3DiaQfDW?8ZvkyGFddsHZp!mM85iCpv4SkDhOuRTSeot5kOvstZJFfHtzv4P5aj2asiliICYOXSY6lz23VDEZDvNXGVNUCEszcG6eU5s0ZlUFsG9kvFVKNCKJUtgNnGRvcHTRguQDyhoO17tcjC5V5QvO?A1xwgbGIjqKKE2x0yKGkBkrb2alMox6RE?UZe6D6ScOe6liwieO34idlHTYNf3OPyaoyRuONZOHBiHcWITKtRNN3gw0o7t0fUXXvuR2qKvom5u4K9KAbpg3YD5v8hrcYxPbSc8tw0xAEEo74OXH7isFFADXw0rAN4Vl6Fcsuz4ujSw7rMu3cPBHFqC40gpboYfiBEHd4CL22xkVYYN6uOv3fUYvytelWqRn6HYCSPZ?psJpmr4M9g2nXIINENYy1qRUriL1AvQgrJLjlL0js2WE!ZLcc?2ekhGaPWNeBgaSDmxWV51fiMEazWTym4RC1cN7kS5S14s78YDyNYM2wtlrtWpn?W6QgXB3apFmaot90DXxEf2qfQ263!R3FVHie1RHFAxiRKUPg9zjWTdCdnD5XihDq6oiwMmIQBfKF!BMlCfGY6wXKeQ6KSYwSb7GGcbqRut0NqrfD6ujrcxFSfSNw96yMXjoT66PlXQ?5QwKxP9YKCT!PqCT5UYW4lEfo90dmD7trC8G8xpoN955sW1MX2k5tnLoXDlopyCiGt7FT2uB2k6NgpCW6sWr7NQ51EY6ye5QWs2rcEbsaq4CvS9Xdu0OPGtnYJxP22oupTi6RqW8bCNDgt12aoRylgPoOD8wvFdYK3YaHxrpY4QAvvFvjLL5hXqr48hoXXBRONWsYFeipusgAEwQpeGA7ePcNfeglHsWo?gHYwBoO91MTTCVuaammWuOSt8QSpvs58YF7Rq9UQ0C3v7QhixAnIQpARku1p94AfSaJcmwQl8JHazh5qeH6Txz!tTFY3LQRYSh3LBdpeglVCMPfApF60HADOgFjw?FSAcoDMoZeZjO0LnHfbJNVSFgs9fxLPqLVKp0NaWeppFc79OgbYxqg3cyk9i00XS3EFIrBiAnXykc7vIDHIgmLJOlSRqLVZN4RKxHhFq0CvAGl?sa9kd?nt!EQKGrLqLPOUy12uR02tZoeochXDnupnORki?377yKdEavrJfFHXs1CEJlwoWAzrp43HCpk?gKr3DpZJjkkO4YtkKFsOJS9zo1ke1J7tNxkcoA3IZ5Mx8BiTyMaKq4b9PJIP8pQOucEXF93DT0XZrllslQ9d4bHJQe3EHFDDjp9wZCRsdHmuZzPIgKeUuecxkcXBchc0PVj6p7lReay6HQeK08lGUnUdl7VYlUvIs8g0gqVtPbfbD8v2gGYya4aAVgHOXkdNeG2L1J?gTakWbTvJXE6UtZsZRurSqpOzikMoh4rlNk0SMPCSnM4JxPUO70Vagwlm3S5tFnalPNwv?ZOohu!PZ6FAJh1w4Aexybmg8GbEJr?QGr!wjxx758!hAR!oRP6MnCnRyffVdYVIyvSVdkPhliSW6g0unZM5Wx7uPMYY5wzFPPYqv7eKJRKWXfI6A22cPKicNxkpxQEmNhXAJYtoYeCBHJikZuvDtAqJGMaVNJLd0cKFtMWtuWTnfBHb41PVR1a7cLreMGGFrFhBLJTlyIo0YVjGW?0j5pvKRElwLRQUkMbh2jjDuR5rO6BKlOL0WhiGMYj0RZ2Zmi12Wy4Mb?cKuhFj02kqKwFv85krygYKqKO5EEt?DmIlFAYsAGq6SVfhyg6dOAPAW3xWeNzM0KTXUfXPSMMfMjjeHuLjRuruUVl7Q21mptVfZg7PbT8ozdxVQKkAr3NZvR4y3ZTkGGwEwVQybcf4G3iEHby5HNAuEJwrCmflv3pgGWC1deK1p1CYtuiL7Rr7NL7lYpKlVKhso1z7yoIpeeI1hZph8G3Y605NC8HKM0jSlW3LqfD21ukR8m!a6hbD1Yjk0nmdyXQOcyrsQDjxKQEtPAD3!9zXTkVvTAEfN6W02ohvFFJUjrhF9VSybGtGO7xKVLeCWBLeXCNeugb0VsvYX4ejuArruRzo2jD3t?BENNWAcCAeY5Py5lk!IPbzsU2juSerNjXUxWX9q9uuEN3bNsPvd63Hcf1XsiukY543FMzltcscMCy7JYsn5WCskgekta6sqF7bRP17oa1x5zAFN5KGv9Lnx1Xtuvew!lhG8HW62CuczPNasDxWFAQgGRhT?bL6OidrC0aDA7lV6?4YcMrlwwGwyMe92T606ypzKXNscqocLtk5Q3rP2QJtDNAXDzVEwxi1tuFKnj3Ay5vbOw31nfjUr2xUYuYgoRL7XZ0BFX2HqucNVCBDbl0rJXJh3BVYdHQr4sn?y3SCIE1pQmfEd0wwacg!8xOLNp6Z!JzpMgoZ86WePQqOAcPzlupT9Z9mWhAtiW1TsW1pc?b3GC5?iLqg1UA9hZempKqUj5qhq!C4oJUpo9N!QssE5goI78f!KjU?i!Creg0vg?EYA?D3rZjNjhJFRxsZ3R7wDKe6pPFhJzCx64obcNs7KMxjoHv?PtLSLheFauUZD?7OwioJ50iDhWVf69I1kkY9nWSwalWnx5lBHOf!EYK1TBQNRwVT7EaoPuwnoaiyTCn37YpKMi0Ut7CdTsUu3P3OwyABnDG1BMACEMjwJ0g?HLEBwSEm0cdkrYFXYtg7BNorGKxqBkWy5nKX87jFMDenpff93BSiSOG9hwHH8dQu7DMpxTclV9Gbek6eZOVQzG1iSZhmB08eDaoh392TgK4OzYi2DhUJ8TVBIDLBxlC7tltLWVI50UsGnBqIGAHqvadLlOfwn7JjKVVqxeZwJYRqBr4cO3P5R0GEmPsDS4jhptUQ3Y08jjugBConrmOfrZespDm8yw7C0U87PSPcgsse06CyhWqCnuAGBlUCAeVg3jfgHCNaAYA28NbEaAR2Lu46!1FJVSreHbA3Fjv9xJ5gyu51ovIDN6jQkjXB5GcPUeHVSufqqrnvoj0Cg3YfSxGRrrAPEsUIa5OXPPKjFw8oFlpR2mZ4ZXF?qUPQKwb5HMyvkRR3d6TWAdMbc4w!b29GaoDjBWykOXWJjOOzr0PivdnO1Bivvdj1Qn3vav2Eh3lTBNKNgn5Y7Z9uCFBMYpRpc784NfKKLRNvUldLGRHkIha9jgrmxJWmM4iOyFOFuApHBOllkso7cPKl4OLrBUYjbkfCITCytNXv3XqjUGev24ZayKW?OEEpnts!KntYpCufvbsqUFWWEIEY7Ul9tTECy5FTDfkA4CsxoAEvf1bKHUxL2wUpvQAwqNuBOCyasisOO2sVGATjhqL!EFSEG8HfV9PMj?iqAjfuewxfiqPgTZsNM3n1eziU9DvT2PDAqbFs7nK5nvWyLXy49KmV5Be358TSF67KXLIw1a53gkK8TqC4LJE6LtPoZI4K11?gCAVCSEBq?fyQp?A4JKp9VSDSsQTjf3mD5f7cz2QKXjQTQzEy1KYXaSLc2iYpfT!ETdK7e4eRG7ZyFh7nQvmqHBzALpVU4BhzUo0UV0BypxF9q99XbmJiC8EV?rqFC0iY95UPYv28!XSgezUws4kF5vMYst31FtsII5kveQjrOqh8k2uePgwx4Lz75H6y26kNGMjVpJ!ID?o2whzlicRPADazCp5hlu1xEYn!Cj7MudRnmFTwNYbXEFUWjTz4ltpyJFtBFlU1tv5Z3PYLXpOnY71OeDfsuDbpMovku9nPnrkmErbk62HrA0hNhzuxUM0Ep3YJ3Ax8ILjtp1LwJWoLnIfDuo8D8MaBeMaC?INVunt!BLXTCN7OQfNzxdwNxgSaMFGqRmgnZhkHXRGFSbgHZIuZJEG9rp5pZpZ3!?wRldScL6ADMKs9Oyuan8T9oN8xBIfy9b8P15HXKGIBD2SQoqPcQZm6VMh7GJ!?PJXZoJeUJHRjJAmgIrM5PGGnkgrkL8gI3rQTR4tVxS0bfBgm9w3E2me60yEbHad2CRQMI2OKgwLW4CWzUIHMevpEWkJXtfD1EZPV5mMoRjXak6uQySGmiDMlmrzbbMowh24mhV5IdTH?JN7rDQsdStbOgkh4o4vHHtx1YWmrjKeFPWCYJUaI1jGDdA8NbvByC1E6l6sjWr8Y1U8u?LEb7jYwaImk6L0uVfrSmlnSvixO8O?OoP?SgeNvf5Dw30hd5OXmC9ffgJTCMaKvYfnQoNvP3jFuQoKmVDNqwNYvL5PMWAlgu9eIPL2!IDjpbFKP4bzo40G0jei4s!nEbacY4l1YN3ooYpk1FwFkeP5qPG2MnEAPQV4UobVMHJyLjvaHp2RVxbIBpnw2Ih9LdvIzWq!CHt1Ah6Ew4S37Pk?gTUdcCld6GrUi?CqKNeZAKd7ldqVtumzuudENBSimfrzIMuZv!Hs8agOVsyukxelEXZ6vqZ39!PPkddw5zXpQnXHn!JcvcNb4lGMUwJjFIAUfioU5VEEQZx2DIiLVYIK0!BE0cjAshLi0QiS6FIP7FzYsrU8Wvin4mffVg6Uiqgo50eJp6n9kx6nEM0FjYsRNqQyJo5kJ5sEh0Q0yGEM0KSafsitS99F!VL5?PIkihCEKVyxvEQKg0XL6h7ubq!p?Z!ZOY2Ti1Fb1QF0qIc4!xECZsati9dbJDTqh7pIa9322SvK2oYIpCERPljprrik7curmb157n8Jq8VQgdq1r4hXc13ipN3BGL3jefLNpXezsd3E7mZpvL4xXcXzCxpnN40qQyc9k0jJzenC57NkOQVJRpuAmLQ4WXrjSMFccKCGc7IWpq0ML0nQGnw569Aix5qB8pX1B4RsvCglPqHYsB07okXdZ9lS6NJ9XvBtxruh627n8m4BMI5J2qetF9i1jUUsUE!0Sg9K2y0b?CDLUcUPubEUKJMPTzHZBtrabfSk1UYw5jTiHB8p77sHwtw8ZaheNdXX7l8xDxRjRWVR8ELRCnOOJPusSm09SYpLS9y5EdErLe6ezxjLGP354cLFJhvbZdjhXGgGfy!IIKT1M?10wde7jZ5KvIzE2ZtjxKg7fLjJIyNvAVv62oYeI4dMEOW4xMoNQRh6tvEHVTCtLTU4vb4QmveeOAEokWB8G6cDsao?tquEMRDVB8ZqKRkX6j6StGhbrGshBqNYJptAibZxePf!oRanjc8wPl6qeYqpTlWLOoEanwJA9FWRSznM9GuOx2N7sfBKkgG6JB!wVeCil22PpXMZEkiZVNA39YMhPo6HDWeW2bd9uRPQM59Ec65iKGFrw4MSKdZLBil7BoYzCVtc2jn0GNPZwrtsS0iFQKKWrWlpLWQF3XR2GXTw6vkg4TbIiUvC1EPO5r?fZ9u0urtfUgRRbFMDBwx6Ifx2pdbRdRZ!LIOqRk0kvhooz27YDA640o7xtJd0gZ1WRbU2fHN52uM4loHmeQiBg74hBXTnMRePsdTZPp6ikJzG02bf4S19u3N4bUrJbDG1lNhxNwKZr6RhImY?aW?RvAsxA3IpshPtMJ98TGbJkzd5pSHtlg6!AKiyzK6rxEzSwj1K06jRodvwU1jlhulQqixoeo0PwivtVXZ8EizXpYKD5Bs86?YOKV4mqi988Fl5FCwot1jUvTki!klXqGWNAtUhlYYht4FD92pN8f7!f4smITm4cjVqvxysOpgzNDfiKpci96jtZW9wU3tf8Y7ZZTkTeCyaGjcsUtwAIBDuZww6vhNd!59egOvqVOW7B!2?5?ewg4WqUAnj64rGuMMPeLh0aClqqUjH0atkXF0!N?HfTUGsSiVIblvsig8HBqbHk4mZTNataiF92BPwI!g4hubzc?yUeqRU1KmGtiOED44bToLWzj5rxT2uyJSNnhqvxNLl9mQ3KIkjHzTZ0SUMVyHfb0IWmOnHCFkp2Z6cXmeqWwxle7E2OaTpyFCixUwIr3DlazUW7w1VHC3TXGC9!X4vR3aWnxHVEV3vM3Wcrx4GWPf5Zoimb9JAgPjxMp!qVIGplyKka1DnQe3M1OU?3QmqbW4RAeyUeCKJ5aYnIiop1jaP4ZWhnK6DPOlzymwh7a904nALt1b1lHH1nM767nsOXKNgBAnywHJLhI9!2wn5KVtY6iNx05nzoiq5ZysrJY3Ib?z35ObZjETL357v3jHwwl?lPt3YFtGiflWJhAIc8QN1phiJ?RfDqIkfX7izwWLoNRjbMfvi4EBG1wavEgXUrcKTbwkT9nAZfB3?vRRhnYmrB5P?23is4Qgt1cAf9NIJkUqQhQV3gxXLT6WyXgydnbOvz3b4nzGq2DZ4gBWQKKS4zmUH98CLYlFUvCgPU1H75pGI9rnmkxx2qewJUtJ6SGfqQKcA8a!ltX3yTiwiKsmA0ePgQLdQhiEcYLGBgxbxAJ9kTVF4arF1fl5nJtiseO7lACZijuPIE1KO3CbR4gpEmLkdSehwD76WAexvcAyRPY?ssfZZyvSl!v28lJgjDyaALqvM45l0WPiNdiF8PZ2iCIRJKujPp6GD3AH6T8qzzMHFwuYQwZv631qN0mo56sq5Te3ac98rV!0if!wLCTqNXfI5pGNv9IazweKPCfp05qn5aBIauy1Ju7ch8nRIf2h3cxDWxCTVLDnsMt7!6hS4x?k9EU!L8ktPDiGZycD6!eKwBpYYm2umJWVGilagsSiQtK6tAefKUK3Nhn0jt4On31jmYhAJMKQnSbirmWQku?CzieqnqL5W3h5P0yZVs44z4YPLMQ10S20CvcTUn?R!3?fq3Kl2vLeVUn2KFl?ugch?LpKT?RXrfyyuIsZw35JcQn4YKhP28?zGh67oMcevCLnReqU7Q6rFk5EX8wpRILnlMq3yKM3HK3snwNUsiidHgarpShS3hiCAKl7r!atrjhODSWKuhxsojFLJ1ADfYbk1Yk35oJvylFmnbADEDiA!zL5eexBWKn1V6jfj3eXizSgimYnjK68oOEoFUuagvLvUrBTEiUS0xlHeNt63K2BHTq9Jp1gOPC45yqZ2e3Ic!!p95ntR9kOJFd1zhf5UNsQ?unGTQf3FK28ntTIsnpGJKSWLHhOlOTRm?PB1liOFZEZr7IyU7Oq6KrZEgiJ1unIYbpRmp1PtD1fPje0FUW0bGSssy7JvX99IFPu2CMGZS0NlQSfKLTK0eER7i?oKnnOFKTaxIEciFWsfKzoOOnF0QcCtfmfoPSxkHqp97vcOF8MHzaCf8viTO3lXImn0eHaXw524jhQwcOeFJDqg96OXWATMnXHSJD13RA0bwYkFfsvLgoDZG3vEr2dAszmKPunVBqlodh1g5K15IhunQF8n3n3?2PZnuk?csj7QL!PQtnTeQqhFVGutbnl!?I3EV4nrgWxASTDnMCdowyEUIkErHeix?HTja0o2ydndavJ03Lrm6dQcsvb385DXSi?532aAJCCR4WdgOcfWhRdLIMUBu1Eqb31v4!nR6WoBOypNsQ?!RnXFpzMFVlfZhi2rGD0T5lIGHzdvr?tvfF3txUn!51k4wPKn38VtjaPh9LXa?L66V2EE??yvBmKyRavmdtQRyEGaQa37ZpYbr6ka4htblbfD!zVQbzbXaPPkzM3Cuu2iJzTiG9gBSC3!fmc7Hy6nOdZEgimmQWF8s!Mt59f93cm3HB?eL1AA62TZFE1GUuL!fh4KPlM80KqfmWoOWt88Xq1J?6c6VSO3M5dRTLL4OM4!Oifu!TlHf1JmJe8oN5Jj1nVCmMP6J72ignbZetGi10LSQa7PPCNRB4FTkqyCL5wGWODWsDFBBgVnUCMfhdnieNVv7FmdFAwgLpW6AmpcbOE5FlPu?0cPPxqXUViKyaYy8No2RSCdUe0INXCstZmxsYabVADXJBrp?v?Nvm4NGLA9w9Puj48uOvhwXehQRY5T4FvU74qS9Ud?fVWOGHj0ykdFoJ8r8CJIjvYhGPgIG2ER8KQqz8v1PPsRe6Hrez7VThIJ7fpyfFvSnUOVSAICC6dD9Zj5eugr2jBYWSY4qjmj?KQhseGairkmwQ3Vv5vNYo4MoSA7zc!A8SZJMjibrdRS7V1sLts14Q00KbxzeG1Qot5tG?LXYQ?Cbn0eXspV0W8h0GKK0tmFJx?DMOI1vrLsZZbhSSCjZq1wL4hcOkSihCSVojeOZfrPXU1KQQertC!PQ3pahbcw7C5xJRfANtsSDcffnA?0xuUQ88lQmJrZYJfiCg9CalubRsCIZVbV8gnH67VrzYbUS1MZ1sMN4MftMzqsSnY?SO0EWS?mOLeyUGZUl0nLI051LidDqIgvpnmFSLRI8tLajZdqGz96PsCIwnGdkE0ZbasBfnkXLxRxQvDALN5siPG2xdOsu7ChUTv1Oqkvqt9XIaqRdcoYOpk3Xno0h!PxLK2bl?V!DbN2FUYDrDFv1izhH834g7RqmunFSpzwLzxbSIKiYfOV8jV!LO36t7RluakbTMEEfULqfBb3ervNDAUX6IH9DOO2OjhN5NaNUyfgxU3ya7do2!osjnx3ucG2AsNsy6mpEaO6QBs1tswP!AR2?MRVYPi1Su3d3TMLEm0?5KMzGOXGIMlmFBtGmnAIwYmBLxgSFKYJ4FEelF?YlNmNBiz7YFbUI4Yq4mvi0RJwPi!S70bhtxNo3NCmBRj5E!JEdMXA2pRRAt7wJmoVGvj2WOoLQsoI49Ia8XRtgKLutaRdq8GnVXCgJKEDyAsr47Md1xUqChphfS2SXQBsLIZLvOev4cMeCWk05fasfzQjI5Vo5rSK0A7yisABbvOO5WW4PcJmPuBg8ZlayyDDBBkOWL5u99dTqCY943N!7xOvcNkl0QgabkZHZJKZElzqBbEcHL1!nizQG5dCc?gc?9a0uDWvaEhZcXCnOrtAqIAiMUxEEybLScEHHwneHTlTdKbd5058GZzpao1BKl5s!KwGO2n3y6EVnpl6q5EKn1tETivlvkGRpo4wXOMwP6h4?cU06bfk0woM6qan3SGrEupbx!CcV2oiL73fzwZ!uDyXoQURh6GFLLNKLRTGahNl2taBpDAGFFZrxgMleTHpMg333eFSKhtHqO6PNRKZ0v92G7yok15wNbNRtoxuPxkPH0wQ5ZTTFcnYLm?5qE0OxFolBQK2lEL4mTu6FUasSFRSSYUQYRbb0iMc!TNe086qmUKJ4lALOeg9A0zuS0URfnCoLUW37?ZiHE0dSR?EWP69KedWwcYaYgxAwDlWw36MZ3hY3Vifa5960AvGtdNVeNiz0yVSzgBUGImRjZx7dnYPnVJBcZeF3fnsoMnmlhRMIVxD2G2FGTMVkWWGJPgW2MYce87ca05IrH1gxBlfXbnWNxzOMNh9HNx1q4TbIhEN2fkn9krYsnWk0Zc9Eh?iMvkncQuu3eVuGckk6!dQzPCIT9nEfDhtk1gT7G6G?KqrUhmHoc7afHdM461VJgEv0KEDKcp?dhk6wrsXj4cDeEKpTnRASpctwEr3oIJTNIKP!CgGU8ZfXJeOYveEcYFWIOg0Qe6wyEftG6g5htCGXayNGV2SmH8LSl7BL2RytXM8!pkG0erXjJbBdmA4K4nk75XypM3jnQpot4!DiIpEzRKvT4ds0pBWNHsQWWJ9uSsBBtf4IODpZe3gdDLYyAnp03zogL7ZocNTWayyMDgl28l5Wg57aXadGUA?Myny6YxVXGrmPOMMcQVu!itMo5HLkXzeGRyg5i3RbZtqX2ugct2joHG1KnqpELZf4DFXNQNjfuA3EpgSewvXzMVs9CiLJcWWsvn8sMj2vY7q3AWdi8J41qzxkWN7978EB!MgLt9yZd2AVUF2ADJm8LvRgLLGuvYyOz3GE10ZOx3JmCVVio8DqVbhoVCJA30FrkMOaeZFLaLglALxTgJ0kcIn0NIUr!wx9Hfp!hn1Yzt22kIzuSknjNmaiTVjrTAvxAD5fjHJYKY4nR23IsCO?9Z!9Vx6!XuTcepbqesLKBKenutUOENCfWJvvw1ulwTXGidmHXXNNRlXHZxU2sPH4CvSLwMcWaBsGWec2XLbR4EPIdf97YcAobDxXAanOU0fEQ4GpsdcDtYvYxEyqxXSOI4fR9iXvc1eaJkTfQ9rOvF5xOsKmuZTePj0YVF5?nSbEaOrbhGPBJcajC5N?xU4ZvTwXf0CirWWQY47MIp2oJfOVdlbyZv3dOJCBTeAPSHkpw3S2UY61dnwPQxj2A3bBSs8YO6QNZ919fqCScAODOFlogh!fe5Q6?G4qPAPwDVNHJd7EmcG5Qnefky?1OLXuiWOqRIGIX3FI?DVrmUJCsOmXysz?32omvQe63L6q9q2CveecbWmDfddLvTcYpcUrXFexbsZK0pTNGsqKadie9gNVWxlvFA6F?IncWIRe4OtycQtj0J2HOVOJe4G9mAifM9c8Y6w520Nz5RmOQH9iKGQqN8E9H6HOG!HegQd?!mCbkN6Bd7ftT3xQJeJMYLZY49ddjk?n6SSzdKFKbjQKARO3mPeypEbjC0Ws?JHABs7sWAacv!HXePGfkN308vvREVEAiBuR52sCos158DMqKrS4oknkvGt1gesVRXFi5xm99NsOBG4PGvfpqhkG2k9gjLzuKwPfhqfzW?jGJWT0hp6xbDDW!ldUvwb6iBu20ZaIfFnW53PLqbusiIs6HRvT6UacU6Wtd6T8Uy!LZLJSAEzl2e83Mz!Fe0FA7mwl03GA9GSRiEStRoL9N34RLEYvUKo3iDwb!yZLqBvKwWnwMRlNsI0IyxpNjkcFDoQM8shnNPzr!hxVmOr3LKMzcHSnRvQuN9Q5h7lVNUHmgh44?Duso3nlkF6vyRed2vpBYrklAtecJhiyjpDAZtIm6qhAvAWQuCTM5dhvcAByWowlhSPt5aw8tPxkref1aDia3K9BhAaze63ylkaeGqOh2qW91z3U2IWadclupVysJfbj8xaww3HZQvqSlc?dmvcApW!jtetIr44Ny8qJvzvnfAp7upe4UWwaxGcnvCskPCvAEovMBawjzaXWsGFuANf3T2siRxNfAVe4LGwmkbgEmv9VvwWkUrMZsufp8LS3kXLkmCQeVC3h9AuWMXPe1ZJVFV7epOweid!B3LhFwnW!ZCoK2zJZEuPHW8WT5d3Ao!hzRnxuMgRjSds4!b8OPWfPZlBM?D2vVfYM0AO62GG0F4FIA9n1F!kMZBjkO8lSJH5siDhV7cB2cTyH?kdBqExDwa2ChJjaSaZh?MRRS4!Cst6wWqx8Vb80Dbg!fqWuwLdeNXUkaaKn9hBlVYi0Cng!uohxTokjf7rWp!6XfYrbBRxjBOj4zVpk8TXvWFEEdYWtgDH6509okYg197Mh1Ogk4fG05Ift9Jd2LvnMWAqj6ZquO0bYrlIiH0LY7vzsZZ9WtZRZzM4pY?S3YsBVH72SmQNPzzF2QoVQd2hK5bElrpLEvNPl7RbFPUYJhHIbuUPLfS4B3Y34kXz!0x9ArIrWFXidJE8ztwFLuXxSEAAnq7V9YOBXjrJTyF!m6yr9SZ4i2WE0WWDB3ncw6uio5?xDOEeULk0Ry3Xpdl7OXiHWQfdkPTZvhwQbcSqm1H6VdjsoErsNb08lQCalj02m2agvjsGUyZiVWH7IesHgHOHLG466vcigsiFITbIbdzIk6!GpsfYVz?FbHYlkvqDRY0yK5QomEcEI3FOnsgROAMDRl0ZVskZtRpasVNZq3ARZ4LkxHka4O9cv6Pl6oxbdk5!K4KdnClgXqYltoRlZJNn0Dm1YN1r9HKRx1nOWyBGMRbt2r2xwz!mJvkS5YmQusFd5uta6Sa0rwb74JRkKCDHMlcbi3b8cQNHMJVM7!H9NRFLWXY4!f2rWWoo?LlQGNs4DPAd8vyRN19vWvBDG4kJCF1vlJJLektJm1nxTzY0jPyvId6CxBj4yl0DclTLRT5wbwbajymDzXVW7PTiJ0GRk9Qg73HBM0KDPz7tFXuSVZw8KLd60mhLdO0rj!BkKLWrdY40E7uYy0y0nWdX1lh3Eo9WTvbaj8qaZNnqMgGcSsHyEdvfSGCqDzeRYLDiYGCxviIUWA0F3cJ406nsbqGm8yEeaUDHaFHD3AOo6vTt4GUJfuJhUsWDVBfOXpc86SmbXXaaBKG95Cx5eoXeJY2ryNe0Y8ZpWsf4rVgeSoBkg7SpUiOIGHSdKQDJnHcm6Yi?3cBUVUOiuKgfvW25PM?iXCcM!FXlCh9KDRTrAwzJjoW!QlUJEmtrb2wJpJxVjw!kQoXIkWS?vt2k6gWLdHaWDjyUqWbk!IXxYgHNiwq00YJNSSNb2sy3?tD2BKsS7dMjE7W2daB1ltz0SD8!T97FZILtQt3XeJIprH1r5GTQ4wGdJ8hAzKSCXp6uAjNrZAXOV7UUZDo4eFHPtXhPmbUezT?52qpDdM!Fop?25SbA1CiZ6uknHo43OIHFml6!Ahpdshf5hRvdDDgXHJX1Pn5ZZkyZhpb1XEn?xs8!lsLHlLRxYRinnfPPgGSSoEeLD56ZV0BI26tkz58kL3M0fwa68?yR7sPDswATYHUSA3eO3D3pQMeU3kULOPtQy1OhvHnE8FxZWRV5JpSqWqA1GOwUWvcIsDOAlFYo?9TV6ZtY5eND6h0ry!k4J3u2PpLl4aDQa9mJPIsjmRdwB3H!ba8z740Ohx7E0IL5OqOWSO3vJhG6izXrSnXVC9l61DWI35o2B9q7WbPguVO3unsnmtjgKGCUT3gS1scSlsLyx3FJqA2EO3rcChKi!GwLcJhz4qjZ2DGVGBe1OV6y9tMxx3jYxbnFDFohjomd77olXZTYcHCoXMnVxuDFCKDcrXQH16fkIxAsYakIjKfPx2v8!r6p4DgS9PtDhor9vwFREX9hvHgDP8Ecvj57QZA18IDqMoum2tO4fWQCYh6EN?j5q1lein9jYCnw7bZG3ID?2ptlvMzO4blU51!2XGvnrryqlVBPb4BjKgIPvtj6rSQHosI1DnJzMiyoU00EPgm?C9A5wNJITejZfHiwAERUpewR9INgYzTHXPgzkaxu0BfJ7mcZGa3xYySUfMMtB4Dzh!tjxrYa8wxSUuS?thhkoJX640!dSHyjS!QldXqF9K2YVmCB4TiZaJNd6Z7UU5nMxvZed0CF0xm6MGzPMtXUwY3wEjDs6h9lrE9evie9ngdLfay43YTXifeagcqwNISeX2ykQ28godGs2mM3xEGRJ71YhOENM16P7gTcNWQejVgblp!KHk6voj5m3p7M1p2OspYkPC7OiCfY5i5hxrTP8S6xyRs5YJOay3KcUCXE7iYiL8TSl?CF6MAAR1YNR5FMPJs?k88qlb8MEbu3coddhSYBlj2top1561prSYF!CCobf8jMrFUc6VbvXGBwMatvLCSPH5DjYC6yfglzKveecPLtqUSjUFPSqdgTA8!h5QBogt0YsfwMFaQS5XLRN6qHKKd58HIhWIhi5iMR9ImV9x5ondyGgDj3oa!pCcZepO2EDNkInAO1rjIkxNAX8aBImOmBPvBMeueot?mrKJrj4fxpvpWgmwjV9N602pSDvgL1JDUOIYfgWV5BviT1i3N68O1!Q48TZWToA!KWG!4yapDisIuGdM2Iv?fYvebi4Rqvkav7P0l1CN?RgVyJX!c2WVUB!6mIR4TDBSuIOuXhlomyvXCh9e8QxotIwJ4sWebc?vFxwa6YQTqGM3qjyZnCSTkWfdwBTLTi7tplg3HCnZQ1pJaFqwEa15UA!fd5szsR4Hy1ftN42k5HAPuyqcEHF?NGw3WvpMx92hJmDSVYXFJILuMmaj?kCZXypIOMAIf4b6yxFJarAfL2HXaHilZs1rNbbaNQs0ShDim3!RbW?ZIvErfnjWy1vTKNavBshvcP1k2K1mHa0nB1bAULW47?mQpcfn4puvE2Xw46uHyc0mszu0xJFwjCFXKdY345VvYdeKWMzyFOOY5nomoZ118UwvQaOxLk7GjKFRBB1jKvqRZgHqklnJy6Vl6TSC5iIgWR2Bb!p?HHgS0sZz5D0rzYOkTtwSBXkgQAo2PqIx3YWEvdWXsdGdRn4Uq4OPrr8ytQOL0gEeM?GJy9oSShgFqCz?ijVUyHeN?vmmPHVnGSRACPP0stjkYs8VyN89n3pnu8xKNDnoDIVCdhE0vRWgGjXahkwNO7ToOvH?J5O?0j!jx4txrc6HK?Es1NK6Qd9AZojnn6v91qfePrTZ9Zt3VrMTdkQjEEeMfMuvr8smFEQ3tOcruJU9s0Af77cJakNqR8uJ2UQrfk?bLhKqOR0yL7ahcvOT89S?hGn4Olp7CLyedxaMV3qX991rsn7Djm56FvnnVwdicL9eqFBnup5BwHTUHgC8KXWWr1LKbr!wHUGZYYpjCEaXkD3SIIwGPmWd4ocA79t6hLBuamOZMWnjva?m2ICMzumnxvum5tGplY4jeXu2lpmcXb4HeKb2Dw4GwnJNON7Pe0Y1DlaYiUq4fI?KzoMZZYra4?s9naRN94aYYImGN1r8KV8MESA!jgoLWFZocXu5gjgrYpJAZhY0m0rA!IhlA!kUPQq0Cw8mxEVsWoxaWCiQn09YypyN4PrUJDxHs1osgg5BVVPCdcjHpXFlkQ0De1aimO7QGeis0oubLriIBG9WRJcHjPovNb26onwAE?y!XNkV!2JbiXg48tpcA34ZoZNFLdV2UE7VsOk5XmAAyTwyzQIIVb7d60Q84IDZtbrMVmK4!ScYFJQfMlDl65HjADuGI6pqlJhs4gZKhh?qtB8xTVC2YbMjZwdIuU7hBKTxt9xHawVs3!jmfAcyiRUM0UqLKTR1D?TuUlPBQZmP4BYCE?e2u9e029QPO9XsKSWLnCyq6sR4ugJ2SEBhpu8uMvJwfMvkx5Xi?00zoAACSy3UJTosC6mJz3wKqq1dCN6AdMs?05tOep1fAiV6gV9YlObyqpGe?cAyePrWdIscufFtyPYL!6h6nhMrogn5IpFMeOgNNMXjuoJKO46huN?Uzj8Iw1nOqxhJhXsbK!KMD04vEXHSogxmDHViLGLb?RnVDGY69OSnUc6WRPpBt9hgk46fpe74sX1rVZvgYrLVT?mB7nR6pfgFgemqANVJjdgO33u1gfTfSWOGXUk?8EKTq1ns1vQzD6Yogq4hYh2mpEXm4OcWOxphd948sAuaUGI5OOLdhFCjVoJ3RnRDPiQBWAcMPvoynU?iGycDbf6TSfxPYKDNwmAHsbfWGo2842rPrwK8?x4im38XJH0M8DBOpKgP91uA5ja4YnKaaB7xM8laNI9tjzCja91l?SFYdptsd7sJxLBgwdI1nbZ69sf21lDBHoxcCIKimL6ldbwbPXxKxSUCQJLQYmT2qW!axuCeLLaWE2hxOJCbc56Yp24fftRWrxOUKgRnjaxS2rFeesTvpsK6qp3l64RFEw51ijv5ub3VoYpLFaPgf1l2ErU2fusLM25fjil06Yl5xb7Rb3!jc4ifboOb9tTV6MY3gKjr77HEIZsIhOxfIb7BTlXvISYwsbKqqpnFdrqIFRlM3t3I4glwiicWAMLQ95MlZI0kVzIJP9BHgt4rm2Y2eivqOxlBZvrHmmqbQa1lPl7VY6xR8Zs2udfApazSAGde5tXa6jQ9mZFNkjjqQfdnEsxg6AepTFGo!u9Fo1b30l27XYk6ukFjNtE7cswGwmSIN72CFYtu2EzgPQxhGNdEasIPr?qL04j5ZSJLf!HYiQan8D5hcJOb8kMpgF!HHpWsSZaRZJDYj1SwA6GQxAHkIuFaKPeK3Dymd52xyWoyoJT1AQdXHSKXJ1KjsNO5RNC9sQtGldiOYoBEHvF2j6NWcq7axxPp3y4tpX340lIDiRL9B33eedId3nu5K7PgucY8Ar2lq2r3lNS70wQ3RXugmUsagxErhdbFzKNutgti5Lj6tzEYaMJSezABKTi02lio8nJl?cUxCkLjssu7PIHaDM2OtGbOOXg9GDtpoRXOCAi1rGyXj2r7m0DfSYAh8BzQIGKvsMWQBFFfVFyDUoC1zVADS94tvxvAMf7yXybbGaXyVSX72yTIzsP!OvlSK4F0wxT?3YhZQbQRg1BPfp9t?ZlpKGuM5stntGukbACN5hpFiDv6XzhgPV2bnQB9CubsqQnaqAAVU07HGFLRJHFmAV?QIkPNuBQrxxP0F2lKPB0l4kKC4U5jyLBZG9vWnpL1syi?IrJp4islIsLnsYzZ2d?RIPCcpL7Ri02xfdACmcZaUR7?pQYNBrRsctI4yqEICgr3v8VB7VwYiXLWZ?8K2r9jfdZUy5AowOAhst9CUm7f3RjEwHrSO1oYP9LE1IZXn7!4j3cPuZoGTEQnf?dLd3vSzn5h3nSa3xF48grq2bZgapi!WoD82f0ocufYvU4HaoZgQdpQEQKe0P?YUU!fGoCv5Hq7ZwYsTgP9DDoXALqdn?qJpgBweKwLgZxsySs2IqZkAxq9v4zOOu41evoHcurk!ETQIZzqp1OwiIRANK5LjxfAabnUGPGOd3twzrUFHU5jZfqOAoZOzA7cf?U2QuiLiEFz553MvvdlXHq5Y6y?d!WwgQce6OBDH0CG9UxHYRdv1tFSxuXEiBWnac5FgpekAWsBBRIezr9bQyQ9aqD5WvJ4bZQRpv4Kph9WuIjWuei4D9CTMoztCbQ6SSY8eQ3qsmj6fYOtZTOKBJELBqlj38uqSFCPFVXqCHClIPeUaiJFKIFesY6RezaQz1O?i6sYoi4BzcgZNVU?LxMl7lJ1tvQHKu6PuGYXUIpZHkQ3vERw9KaLTThsVtRAkkSnYtgDJ8Jm629!cukRBi96QXdrx4NHvpAgn9V65RM6!kAgXegLcE1beg2xcpXS?UX3ZCz0CU?gIXHxX8QKGjE8!C5QEgQb7Q6AF7DKi8CX4ovGIWVOH2g!2i2wm4zuqA11AJJUVoNeFNR29WmR4Im2vWbyLZ?y0!Yi30dQCdhpDjJwq9XeRF4L4ExNZkKGfgQGaCtddxsorXIK81bjwJvs4cCKtr69QkoEZGOuHDSP9w!yvjeIy9U9u1ZXGzaQiJ9lWzpSjphXShsqb4zKOI2DcAr6so0pJ9ubk9lIXTY5JXbqtPz2aqzV2lyrtV7WXBaXbnsmnhWFAsoJjEq8WnKUvVhR!2exX4scXgzQpbSpUoWniTo5QRugnG5zviVx2YyDRHY7xH0H2hUE4XIz0UQX7VyEAzzKCMdFJKbKIYrCSkXzL7f2GXt!LWgdqj8eyCT7RRI755voArhlJAiYAZHkQfng19R134cc4l?wsyV8lvj5iHT4bBjFj3TBnqU9Mvy635OjECF13MIXZyWbYOKyQczNWZJpsDLx5cpjIBJw7JahXOIf!WpwLGzfirOLstI2jnPWfS?DaYZ7j2de9HmU1eFV5tZZwXR42MB4sTsFBTLksNx3Za0kSNikH7pb2NfdNZqXADiXmTzBP7Xxo7qMlS6IREHlUg9tS3Y78O8YxFPcKLbtWtzy0CgM!AM!vLGpMB1dkI3MP9cGmTiIzgo3?aB4wu1w86rqu2LE?InYljh6bMGiZJ?oUVsP7POrYzfqq6kaETsJseEeWrQaHNcUNyHCCFTG7dMcj9seNk4hS2rAKQY1WVoUgFQ1vPd8m02sfXjjxdF9JAQUpNjT2?vRGqiFJ7p8Kh4ObjJpYHux18kZ49pdY?NOLpDxg0afPNpQBv16qzPUQ13p3A1dE1I!I33fdNp0OtzJAcClFh75lMVSlzEM4ATAaktCa99wGNFDbGX1LGjaskmfDfooAut6Rob5hImunIZM2Y5Az5NMolXoX04SqGojwJqz?SbpKeXSA9siqLHlnD!mEG1G74MAocFfAa!8O6uMQ8adjMFJEex6rXAJUkhnb9VXzX!lg6?slbVvHXsdmgFm9wj17kwvvhr9FR4DNrdaV5?N2dprOIGUyj2I2J1OIPOvm5fy8ywMjZgzuaChy2B2wx?9595YQkTl5jDK8WNnqzi9BKfS2g?ACnZKI!qc?gPb8!3QR7deXhqWnT6soYL7sy3xGXfVAB8FPvssE4TVYYWyI52gdStlienf1hMGCpTXfRkqPpNAtuRTWX27XrZm?KRSsRrOrAeLQXTbd2TNhYUJVIdA7wv0rKJar9ToKXKBB2WmqLhMeRswPr40ta1Y0Lv4c!BrblZCEyjH9DN7rTEysB2MsJkL1rJKnv9!Igvngf6qJhKeFw8qpCPp0cmLOhTNLcMi3MsjBICHNZNB9ah1e6R2VAQAfBJvrWxHcX2lPEAadiU1NohWfmxM8sNno3XoZ?N0xPDEsTDoPZVV4mr6Kxoqa2A6psMfhw9AcKAsTN!PvpLSrItJQF3wBy8QsI?orD4jc95tA8MCOuZq8mHK8jMq8lE!paXXAT0Bm4RuIQNLn79C?DUFsApcVLfuDWc?69rQxJbb5v3WoTXJi36asjaluloNsuo2RUaS7EV2QePqKFMs1?dkVlRrhnxApG7x5kClciSdSiHvF2FklOKd!k4lr48COCFfyvVFkAQ0YedXKfBmDbJk2sPsSYjsgjj6qvgWNF?5vFCgrB1Z5vyUU8OGl6?7eRsw!E5CK66st?hH7S4eub9Exj5xoL76dglysn5h11kSPzJlN2AYq3g1ZuObuo9efonVyyaIeiQHNtbFJUkC?kKAeKiYoWPF1Ev1wurzUsE8stRGieWUAkG?2htbSiLydSOTDG!00hNAz2z!MKU7YPqEtL1ImDhHhkWd05X1n5ziWfry8oqkmu8uQqC230gCiRsJ3sCUzKhnPpKRV?bTY!I5fU1wJ1Dz8vuFkE7wqeiSgcfXBYEZv4489J3qwxXkUTKGNHRjlrYtsPhK5YG15oncKN1F7Cgh3tW7EAIcauMrOHxW9bHOXKBhJvP5Y5epubRehkuicWbSNEKRC3PHKNPDv0H08lDqsmEvuKXUsNJSc5tii1rjxynCj0lmZYic3ASp0xuMNhB4I9tgTIU2IDBEBwCxVhdUPj4sZM9tFH8XjCUkzHn0quDMfKgcJRhe2kVmQTOIuFr0uT9yQFvAyRD6kOo3eXhZk216i9B1asPP1JHBt5zQqqChnvD6VibUiEPpqu6bo13zwAbNLPKT8XDs3EwzmB0OKX80Pu8Le?vJIC7nMa6Uf5jVh4YRJRnh1uIzZ2yT?pg4vwQuGGLkS?DtI5zsGmNCXXV9C!nH1z6cT2s8Sdkm!bo6a1pOh?w63pvxh12AnNQP?C5WGj89KoGPeSNR1OK40DrNMSeRhjbDzkhhOusPFCTuo0NchFaCzgAqdH6JL9r40022aF!OW81LlQEreYpFhQ3D2X!UgOayNbuvzHoviHOEgmQeAaBCmXbFCR0ScIGjOIu81aOF00fhzCBH6VEFastOpfRd62em4mKlsSQTj40NejUoqIrXSz9QmiNEsmlFvlY2VzUp3YZ2GtmKZAaTjx1bz26s!H!ZYFV125SHJRVGEaTdrjCHWBOQboWnGAl?2kValgtm3TeEtR4FFUZ5xWIbh6RaqLMUVfjF3o0bdvblopq0GuZgZRL7trsh5Nfet57TiwxvkRw9KldE3Zeevg03bqPiSgSX8qJ9Q?UFcf6caBek?A0QwTj4uQ7TNbg8JG5JUf4nuGdQhVZMuy8aWWL?OExRbyuea41vjIv5GOZ5dQy4yw3GK8A2DKdf3PbbYfn39RNf59BKW9GcNA?3BozJcjeJemQsmKqrabl6RAal9Cw7dj2IAksXeiivCJ77Q4moeslO8Egfh5x9hcWz3ZaH7RnHsBlCqxgaL5xIiTPwW8H6kMqdlOxrTAD72g3uAT1bNeoPGDRKDuUQlUP1uGqf0l5CFu2ZW2Oxg1hBTFtCi9dqrlPZ!vYa97XT4VVo4e8sKluItEv2vQugyb?LMONQKTD10py7KCFLWaGq8KSL5263YLh6!YhLD31NJsWEXfF4YPkNWZsivz!IR5I0MK88y2xijZOG5SGTh5oUD!4JLq68vTHcdde3U!NUhrn9hF4NHUNRV2ogOCWgOSHqTJHvwYZSgGVvWBGp13ookwHEvlYZHCwHnjSgIhGfn5iCB9AEKwB1?VJ5D4ua0sQEQlHVlYWkEeLvrY?mgxZzaQZvq73KvfPV3?U!7E3d7cE05mcTVwA!q6keIXEdsXQd4xjmD5oOYy5dg252O4naI19Df9W2SmGPdIhCjJG8RsZ4ztva6retRnUSW?qIjBNoSPDpmFB3YgYCmcggvDr8NDuTZDZsp2gy3ely?i4FLFiyTf9e2cQ8S49nlXUt!yfoaNvXTHscK8eVe1ztdZ39OESvyBQ8c6ZT1T93CmojNMHOL2Nx8HQNRdc9MIdukknNhsZQQvB9W4AkhACwF?E2eNstVfDDVQmsl9PPa9UZlrk5Z6TUTw3VWXBwD1w5krwSuqBz?UHDiEr9YtjJtZBbVPZbHzof2G3oVHk42s!5BAWYRHUMtTVZqf2MRSppe?eGG0ZUBJixrD45XgBs6V4iaqgn9bkZs5oRVIRxVupME1?Rq6snwK8Ijn1ZSA8RTEUedTpOJX0PmW5Bj0f77pa8nnDsGdw842ur?YMKBqGX3aNVSNkcvgOOX5nOJcIpUvGVZLDfy8tIbK4VfABacJx0CkQdv2j4qXib2raEXvJQdDBRICWlp5ZZlLabhEL6vtl9EGD0CmKivY3rLtuPXhnMFOGatTRZkisU!T!ba6vZQHvQQEof8z0HM0szKC58CBO8p?BmvOuVJ5cbHJRplD48OO20MDdCvaeeenlWfuXjYMu2OcziukgqMjp6SGiBgnhCfDJkX9xW08AkhsBqoNDaxvuLXtx8NY2YMGvbAbA884DGqhRXhUIs5RSNzJvvkyvlPaz8SqaVjt0?NpmRTQmrmUpUSxrhcfCnCgF7gaCA5pLbIcNzMDS!4kKlvfsfFd9JC!F!0hL59971mhHTft3LLq3n6OYJI2gvspZJ9nchfBYPudYaEFkeqoDl!syxHXpZHcpt8i3UQVvvUxoVsPQlQXcUKEfYz?jkT4GUQhoPYikFbQpVTaRD4w1tvSWXluQGCn4joQhToCa1203?rKFOBU8hJpqrMZL!w7ljTUmaHQvFqKDB13tQBKLbSqnaLEtYJ10BkOUikCPSmVj!804LCO9cwqOSJc3CE6ApKMGvlam90!IbxVgTQdP!Y1VlcNY5p!wFhY?T7Oq6M00vZntrLl?pcKaJ8Lvqc816K9FTPh?O3Sfd6ve81laUzg1JlIOrEWfHYQG8grD98EQDR17wU5a8ghuFT0jcIuzcsLbFfg8wlrUMZ8ZDabTgTib26XBUCKcRzWtDBnJaD9cWZz4ZZk1XMknjx!bCZ0kKba2CQJKURHXKlMTW30DCXVJNvd3ce2Hl3IIuwSUjm6rEeEon8T3Egc99RmHvNxh6pFGWfMNNwnWez8h?t6GON5fsd7D54FMOWl7KYD8aQ53jDe7T3elq4T22YL6mXYPxyME8fH1Sxx3gRzQzIFA!aAWJkP1fJfL!nFYJONANxl5O8bWIkK16M6B?JusAbWN?ts6J5C4K2SrrawI4NbPW?TEgmLxI513fLFV94SW5oPHBmWJcF5YVJEnnkDN460eLNcQ2ABC0XsPWlKwXW!XRGzss6pG7vlj217kTgbWQ1nzRfYp7naBLPBn6WwFG1yIf4j5X8hGo68lfulei3vey8YLDANJo9kEAnKdt5eyFoBcnsdoJyk2pe5Cn0T?Q22JVeB2O81hQ2Nobugr2peF4KTviH3hW6ivXZpya92KAhKIXcW9TKNBqWZYLb0VD3eyBJCBrQGDtupKHZ4AvI2u88vnGkHLO!E8QD!fKpRU0!uGogf3kAYvqCrkPBWHE0W4fCohimOK402WJ6tMVi3meAzqXvWUGG4El5Vsx?Ud4l5V3VdlwaPeWhOoTrIb67llkyf3BhdeqnkOwr4xNmRKw3op95l?gHD?Lkwtnza97fDsRSwHgtAutCamsWTBJmula5oP7UW8awQ8JAfW7GboL7QDEdIqq3t0Kb3IvtiCYNnL?DB8Al266JuLeX99Ph0OByWDZrnUYBwGFsnYrXXcrCMRjHoEAaOC7Lairq1Bu4kktuBq?oHemj4ikELf8GLh3nr1EL6DwIC1500p8dMTXIFcfj5S9qzwJ9MSeU7S2XcOu!HQqKXt!eS5DpS?6JhP6QWgnyupNl4aIG1PbcZDSvRRl0LI?gANZ010R!3NQ3B!Im?rz5exB8HAVveXOjtDrMDxItipxmapF9EeYFnrgh8wJjeynfUjfzXqSbQqEHlCpEbQCUGPY8lhq!w6fTqf0fQBjATb!iVvd8MfPiGJFCByyJ0GqlwJBDBeCuBooG2hRsPjf?rwIJK47X1WHfC4QlpGEPOPFigBnRBiDT878tG!h08HyiYfn9lDD0ePDhBOwauN3dZNP49xWGQlrHhuJejY3?JvcNsCXVTE01KniSfZOBtwcg5!Tm5MMkvJ2BO1p3FvZKx!5qZ?pU5rZjz5mjO3nziVMxSHrPolThNmtA0GUKsjVWmPdjLNs!0ny0DoYFE!f0C5EcEZnMvetqjom9qrH4xNHOosblrgHIDrGkKI5HWUFvSSU1pCSqObd5gvsXeTpn7cnxJRgnHeaT0kVS325QMZgYAtFAzzEjWkl8t?NCNy20shcDBoPi2642vUxaodBwY9zsWFG53PcrEYZsUTDleaQJfV1qna3gCmK1XIfUnY9ZHxuGrqZR55ip064sHLnUb610u9KXLeKJEhdmmtVvUgBGD!Ca24FucbGiyhD1JDjvQ1ai8EUF2b!DiQu2bHqLpOF4VPCmAv6kCo??QZmbc3JofTVIE7OUrJ1HXhBcJILQpuQh5v0E7QG8lEp8UDCTdGDwpSK6O84A5X95fy1h2j1PTSwxEXgoy535M48d8vErQwNPjI4KCiUIfMr4Sc!NiP9sj6zEOevwPmSmixj9FHSFvvRVAwISs!jBYEp3jlxSEiywzHeNuvF9LI!vpeV3wRIZOlaqb!wDXJ8d8wK8ljQCb8vHKWF6ldnARYTAvqAAsvCwDtiC1d!2nlpXNZCap14KXuB9LF53av20NOmt4rl4L0z0JpJdJ2Bh7YW6oj0ouFlpLfzEcG?TW0c!vwhkGHybrikBgxLz3m83vgwJrzG1r14aZHdstmiXA8Q!OjjQuYEzMIwqLpH4QgYvgVTeHQ3Tfs9gmcba9F8e3?VnSHntulpmXDgbavd?JZMWYJ?i2KOYtXuVD?4UzN5UsyJI3nNvqlh7AdYRl6cs3ykxXDbNLemTxVNIcN5h3IYKdCIaGi!N585r3ReBTdOz";

  ten[ 0 ] = fac[ 0 ] = inv[ 0 ] = 1;
  iten[ 0 ] = 1;
  int inv10 = mypow( 10 , mod7 - 2 , mod7 );
  for( int i = 1 ; i < N + N ; i ++ ){
    fac[ i ] = mul( fac[ i - 1 ] , i );
    inv[ i ] = mypow( fac[ i ] , mod7 - 2 , mod7 );
    ten[ i ] = mul( ten[ i - 1 ] , 10 );
    iten[ i ] = mul( iten[ i - 1 ] , inv10 );
  }
  int inv9 = mypow( 9 , mod7 - 2 , mod7 );
  for( int i = 1 ; i < N ; i ++ )
    pp[ i ] = mul( sub( ten[ i ] , 1 ) , inv9 );
  for( int i = 1 ; i < 10 ; i ++ ){
    dpw[ i ][ 0 ] = 1;
    for( int j = 1 ; j < N ; j ++ )
      dpw[ i ][ j ] = mul( dpw[ i ][ j - 1 ] , i );
  }
  //for( int k = 0 ; k < N ; k ++ ) // k - j
    //for( int dgt = 1 ; dgt < 10 ; dgt ++ )
      //for( int i = 0 ; i <= k ; i ++ ){
        //int tmp = 1;
        //tmp = mul( tmp , C( k , i ) );
        //tmp = mul( tmp , dpw[ dgt ][ i ] );
        //if( 9 - dgt > 0 )
          //tmp = mul( tmp , dpw[ 9 - dgt ][ k - i ] );
        //tmp = mul( tmp , ten[ k - i ] );
        //sv[ k ][ dgt ][ i ] = tmp;
        //if( i )
          //sv[ k ][ dgt ][ i ] = add( sv[ k ][ dgt ][ i ] ,
                                     //sv[ k ][ dgt ][ i - 1 ] );
      //}
  //for( int k = 1 ; k < N ; k ++ )
    //for( int dgt = 1 ; dgt < 10 ; dgt ++ ){
      //if( dgt == 9 ){
        //for( int i = 0 ; i < k ; i ++ ){
          //int j = k - i;
          //if( dgt == 9 and i + j < k ) continue;
          //int way = C( k , j );

          //way = mul( way , C( k - j , i ) );
          //way = mul( way , dpw[ dgt ][ i ] );
          //if( 9 - dgt > 0 )
            //way = mul( way , dpw[ 9 - dgt ][ k - i - j ] );
          //way = mul( way , ten[ k - i - j ] );

          //way = mul( way , pp[ j ] );
          //dp[ k ][ dgt ] = add( dp[ k ][ dgt ] ,
                                //mul( way , dgt ) );
        //}
        //continue;
      //}
      //for( int j = 1 ; j <= k ; j ++ ){
        //int way = C( k , j );
        //way = mul( way , sv[ k - j ][ dgt ][ k - j ] );
        //way = mul( way , pp[ j ] );
        //dp[ k ][ dgt ] = add( dp[ k ][ dgt ] ,
                              //mul( way , dgt ) );
      //}
    //}
  //printf( "magic=\"" );
  //for( int k = 1 ; k < N ; k ++ )
    //for( int dgt = 1 ; dgt < 10 ; dgt ++ ){
      //int vl = dp[ k ][ dgt ];
      //for( int i = 0 ; i < 5 ; i ++ )
        //putchar( encode( (vl >> ((4 - i) * 6)) & 63 ) );
    //}
  //puts( "\";\n" );
  //exit(0);
  for( int k = 1 , ptr = 0 ; k < N ; k ++ )
    for( int dgt = 1 ; dgt < 10 ; dgt ++ ){
      int vl = 0;
      for( int i = 0 ; i < 5 ; i ++ )
        vl = (vl << 6) | decode( magic[ ptr ++ ] );
      dp[ k ][ dgt ] = vl;
    }
}
char c[ N ];
int ans , len;
void init(){
  scanf( "%s" , c );
  len = strlen( c );
}
int cnt[ 10 ];
void go( int bt , bool bnd ){
  if( bt == len or not bnd ){
    int res = len - bt;
    if( res ){
      int ps = 0;
      for( int i = 9 ; i ; i -- ){
        ans = add( ans , mul( dp[ res ][ i ] , ten[ ps ] ) );
        ps += cnt[ i ];
      }
    }
    int ps = 0;
    for( int i = 0 ; i < 10 ; i ++ ){
      if( i ){
        for( int j = 0 ; j <= res ; j ++ ){
          int way = sv2[ res ][ i ][ j ];
          way = mul( way , ten[ len - (ps + j) - cnt[ i ] ] );
          way = mul( way , pp[ cnt[ i ] ] );
          ans = add( ans , mul( i , way ) );
        }
      }
      ps += cnt[ i ];
    }
    return;
  }
  for( int i = 0 ; i <= c[ bt ] - '0' ; i ++ ){
    if( bt == 0 and i == 0 ) continue;
    cnt[ i ] ++;
    go( bt + 1 , i == c[ bt ] - '0' );
    cnt[ i ] --;
  }
}
void solve(){
  for( int res = 0 ; res < N ; res ++ )
    for( int i = 1 ; i < 10 ; i ++ ){
      for( int j = 0 ; j <= res ; j ++ ){
        int way = C( res , j );
        way = mul( way , dpw[ i ][ j ] );
        way = mul( way , dpw[ 10 - i ][ res - j ] );
        sv2[ res ][ i ][ j ] = way;
      }
    }
  if( len > 1 ){
    for( int i = 1 ; i < 10 ; i ++ )
      ans = add( ans , dp[ len - 1 ][ i ] );
  }
  go( 0 , true );
  cout << ans << endl;
}
int main(){
  build();
  init();
  solve();
}