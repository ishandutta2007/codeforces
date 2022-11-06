var arr = readline().split(" ").map(v => +v.trim());
var n = arr[0];
var p = arr[1];

var a = [];
var k = 0;

for(var i = 0; i < n; i++){
    a.push(readline().split(""));
    if(p > 0)
    for(var j = 0; j < a[i].length; j++){
        if(j === 0){
            if(
                a[i][j] === "." &&
                (a[i][j + 1] === "." || a[i][j + 1] === "P" || a[i][j + 1] === "-" || a[i][j + 1] === "x")
            ){
                a[i][j] = "x";
                if(--p === 0) break;
            }
        }else if(j === 11){
            if(
                a[i][j] === "." &&
                (a[i][j - 1] === "." || a[i][j - 1] === "P" || a[i][j - 1] === "-" || a[i][j - 1] === "x")
            ){
                a[i][j] = "x";
                if(--p === 0) break;
            }
        }else{
            if(
                a[i][j] === "." &&
                (a[i][j - 1] === "." || a[i][j - 1] === "P" || a[i][j - 1] === "-" || a[i][j - 1] === "x") &&
                (a[i][j + 1] === "." || a[i][j + 1] === "P" || a[i][j + 1] === "-" || a[i][j + 1] === "x")
            ){
                a[i][j] = "x";
                if(--p === 0) break;
            }
            
        }
    }
    
}

if(p !== 0)
for(var i = 0; i < a.length; i++){
    for(var j = 0; j < a[i].length; j++){
        if(j === 0){
            if(a[i][j] === "."){
                a[i][j] = "x";
                if(--p === 0) break;
            }
        }else if(j === 11){
            if(a[i][j] === "."){
                a[i][j] = "x";
                if(--p === 0) break;
            }
        }else{
            if(
                a[i][j] === "." &&
                (((a[i][j + 1] === "." || a[i][j + 1] === "P" || a[i][j + 1] === "-" || a[i][j + 1] === "x") && a[i][j - 1] === "S") ||
                ((a[i][j - 1] === "." || a[i][j - 1] === "P" || a[i][j - 1] === "-" || a[i][j - 1] === "x") && a[i][j + 1] === "S"))
            ){
                a[i][j] = "x";
                if(--p === 0) break;
            }
        }
        
    }
    
    if(p === 0) break;
}

if(p !== 0)
for(var i = 0; i < a.length; i++){
    for(var j = 0; j < a[i].length; j++){
        if(a[i][j] === "."){
            a[i][j] = "x";
            if(--p === 0) break;
        }
    }
    
    if(p === 0) break;
}

for(var i = 0; i < a.length; i++){
    for(var j = 0; j < a[i].length; j++){
        if(a[i][j] === "S"){
            if(j === 0){
                if(a[i][j + 1] === "P" || a[i][j + 1] === "S" || a[i][j + 1] === "x") k++;
            }else if(j === 11){
                if(a[i][j - 1] === "P" || a[i][j - 1] === "S" || a[i][j - 1] === "x") k++;
            }else{
                if(a[i][j - 1] === "P" || a[i][j - 1] === "S" || a[i][j - 1] === "x") k++;
                if(a[i][j + 1] === "P" || a[i][j + 1] === "S" || a[i][j + 1] === "x") k++;
            }
        }
    }
}

print(k);
a.forEach(v => print(v.join('')))