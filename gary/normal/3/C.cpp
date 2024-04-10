#include<bits/stdc++.h>
using namespace std;
int main(){
	map<char,int> qipan;
	string chess[3];
	int sflag=0,fflag=0;
	for(int i=0;i<3;i++){
		cin>>chess[i];//first X     second 0      . 
		qipan[chess[i][0]]++;
		qipan[chess[i][1]]++;
		qipan[chess[i][2]]++;
	} 
	if(qipan['X']<qipan['0']||qipan['0']<qipan['X']-1){
		cout<<"illegal";
		return 0;
	}
	if(chess[0][0]==chess[0][1]&&chess[0][1]==chess[0][2]&&chess[0][0]!='.'){
		if(chess[0][0]=='0') sflag=1;
		if(chess[0][0]=='X') fflag=1;
	}
	if(chess[1][0]==chess[1][1]&&chess[1][1]==chess[1][2]&&chess[1][0]!='.'){
		if(chess[1][0]=='0') sflag=1;
		if(chess[1][0]=='X') fflag=1;
	}
	if(chess[2][0]==chess[2][1]&&chess[2][1]==chess[2][2]&&chess[2][0]!='.'){
		if(chess[2][0]=='0') sflag=1;
		if(chess[2][0]=='X') fflag=1;
	}
	if(chess[0][0]==chess[1][0]&&chess[1][0]==chess[2][0]&&chess[0][0]!='.'){
		if(chess[0][0]=='0') sflag=1;
		if(chess[0][0]=='X') fflag=1;
	}
	if(chess[0][1]==chess[1][1]&&chess[1][1]==chess[2][1]&&chess[0][1]!='.'){
		if(chess[0][1]=='0') sflag=1;
		if(chess[0][1]=='X') fflag=1;
	}
	if(chess[0][2]==chess[1][2]&&chess[1][2]==chess[2][2]&&chess[0][2]!='.'){
		if(chess[0][2]=='0') sflag=1;
		if(chess[0][2]=='X') fflag=1;
	}
	if(chess[0][0]==chess[1][1]&&chess[1][1]==chess[2][2]&&chess[0][0]!='.'){
		if(chess[0][0]=='0') sflag=1;
		if(chess[0][0]=='X') fflag=1;
	}
	if(chess[0][2]==chess[1][1]&&chess[1][1]==chess[2][0]&&chess[0][2]!='.'){
		if(chess[0][2]=='0') sflag=1;
		if(chess[0][2]=='X') fflag=1;
	}
	if(sflag==1&&fflag==1||(sflag==1&&qipan['X']>qipan['0'])||(fflag==1&&qipan['X']==qipan['0'])) {
		cout<<"illegal";
		return 0;	
	}
	if(sflag==1) {
		cout<<"the second player won";
		return 0;
	}
	if(fflag==1) {
		cout<<"the first player won";
		return 0;
	}
	if(qipan['X']==qipan['0']&&qipan['.']!=0){
		cout<<"first";
		return 0;
	}
	if(qipan['X']>qipan['0']&&qipan['.']!=0){
		cout<<"second";
		return 0;
	}
	cout<<"draw";
	return 0;
}