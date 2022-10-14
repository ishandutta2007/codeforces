s = input()
print(all([
    s[i] + s[-i-1] in "AA.HH.II.MM.OO.oo.TT.UU.VV.vv.WW.ww.XX.xx.YY.bd.db.pq.qp"
    for i in range(len(s))
]) and "TAK" or "NIE")