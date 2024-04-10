private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
var flag = Array(110, { IntArray(110) })
var bomb = Array(110, { IntArray(110) })
var vs = Array<String>(110, { String() })
var n: Int = 0
var m: Int = 0
var dx = arrayOf(-1, 1, 0, 0)
var dy = arrayOf(0, 0, -1, 1)
var ddx = arrayOf(1, 1, 1, -1, -1, -1, 0, 0)
var ddy = arrayOf(-1, 1, 0, -1, 1, 0, -1, 1)
fun isValid(x: Int, y: Int): Boolean {
    if (x < 0 || x == n || y < 0 || y >= m || flag[x][y] == 1) return false
    else return true
}

fun getcnt(x: Int, y: Int): Int {
    var cnt = 0
    for (i in 0 until 8) {
        var tx = x + ddx[i]
        var ty = y + ddy[i]
        if (tx < 0 || tx == n || ty < 0 || ty >= m) continue
        cnt += flag[tx][ty]
    }
    return cnt
}

fun dis(x1: Int, y1: Int, x2: Int, y2: Int): Int {
    return Math.max(Math.abs(x2 - x1), Math.abs(y2 - y1))
}

fun main() {
    var kkk = readInts()
    n = kkk[0]
    m = kkk[1]
    vs = Array<String>(n, { String() })
    for (i in 0 until n) {
        vs[i] = readLn()
    }
    var sx = 0
    var sy = 0
    var tx = 0
    var ty = 0
    for (i in 0 until n) {
        for (j in 0 until m) {
            if (vs[i][j].equals('T')) {
                tx = i
                ty = j
            }
            if (vs[i][j].equals('E')) {
                sx = i
                sy = j
            }
            if (vs[i][j].equals('X')) flag[i][j] = 1
            else flag[i][j] = 0
        }
    }

    var str = "NSWE"
    var ans = ""
    var key = 10000
    while (sx != tx || sy != ty) {
        if (key <= 0)
            break
        key--;
        if(bomb[sx][sy] == 0 && dis(sx,sy,tx,ty) > 1)
        {
            var curx = sx
            var cury = sy
            var f = 0
            for (i in 0..3) {
                if (f == 1) break
                if (!isValid(curx + dx[i], cury + dy[i]))
                    continue
                for (j in 0..3) {
                    if (f == 1) break
                    if (!isValid(curx + dx[i] + dx[j], cury + dy[i] + dy[j]))
                        continue
                    if (dis(curx + dx[i] + dx[j], cury + dy[i] + dy[j], sx, sy) > 1) {
                        f = 1
                        curx += dx[i] + dx[j]
                        cury += dy[i] + dy[j]
                        ans += 'M'
                        ans += str[i]
                        ans += str[j]
                        ans += 'T'
                        break

                    }
                    for (k in 0..3) {
                        if (isValid(curx + dx[i] + dx[j] + dx[k], cury + dy[i] + dy[j] + dy[k]) &&
                            dis(curx + dx[i] + dx[j] + dx[k], cury + dy[i] + dy[j] + dy[k], sx, sy) > 1) {
                            f = 1
                            curx += dx[i] + dx[j] + dx[k]
                            cury += dy[i] + dy[j] + dy[k]
                            ans += 'M'
                            ans += str[i]
                            ans += str[j]
                            ans += str[k]
                            break
                        }
                    }
                }
            }
            if (f == 1) {
                key = 10000
                for (i in 0 until 8) {
                    var x = sx + ddx[i]
                    var y = sy + ddy[i]
                    if (x < 0 || x >= n) continue
                    if (y < 0 || y >= m) continue
                    flag[x][y] = 0
                }
                bomb[sx][sy] = 1
                sx = curx
                sy = cury
                continue
            }
        }

        var p0 = 1
        var p1 = 1
        var p2 = 1
        var p3 = 1
        if(sx > tx) p0 = 4
        if(sx < tx) p1 = 4
        if(sy > ty) p2 = 4
        if(sy < ty) p3 = 4
        p1 += p0
        p2 += p1
        p3 += p2
        var p = (1..p3).random()
        var o = 0
        if(p <= p0) o = 0
        else if(p <= p1) o = 1
        else if(p <= p2) o = 2
        else if(p <= p3) o = 3
        if (isValid(sx + dx[o], sy + dy[o])) {
            sx += dx[o];
            sy += dy[o]
            ans += str[o]
        }

    }
    if (sx == tx && sy == ty) println(ans)
    else println("No solution")
}