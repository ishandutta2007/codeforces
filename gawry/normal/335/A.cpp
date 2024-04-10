#include<cstdio>
char s[1010];
int n,cnt[26],needs[26];
bool ok(int stickers){
  int all=0;
  for(int i=0;i<26;i++)all+=needs[i]=(cnt[i]+stickers-1)/stickers;
  if(all>n)return false;
  needs[0]+=n-all;
  return true;
}
main(){
  scanf("%s %d",s,&n);
  for(int i=0;s[i];i++)++cnt[s[i]-'a'];
  int ans=1;
  while(ans<2000&&!ok(ans))++ans;
  if(ans==2000){
    puts("-1");
  }else{
    ok(ans);
    printf("%d\n",ans);
    for(int i=0;i<26;i++)while(needs[i]--)printf("%c",'a'+i);
    printf("\n");
  }
}