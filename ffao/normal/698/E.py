import datetime as dt 
import calendar

second,minute,hour,day,date,month = map(int,raw_input().split())

n = int(raw_input())
epoch = dt.datetime(year=1970, month=1, day=1)

safe = epoch.replace(year=2370)
fourh = safe - epoch    
fourh = fourh.days*60*60*24 + fourh.seconds

for x in xrange(n):
    tm = int(raw_input())

    ntm = tm % fourh
    safe = tm - ntm

    t = epoch + dt.timedelta(seconds=ntm)
    t += dt.timedelta(seconds=1)

    while True:
        #print t
        
        while month != -1 and t.month != month:
            try:
                t = t.replace(month=t.month+1, day=1, hour=0,minute=0,second=0) 
            except:
                t = t.replace(year=t.year+1, month=1,day=1, hour=0,minute=0,second=0)

        ok = True
        strict = not (day != -1 and date != -1)
        if strict:
            cond = (day != -1 and t.weekday()+1 != day) or (date != -1 and t.day != date)
        else:
            cond = (day != -1 and t.weekday()+1 != day) and (date != -1 and t.day != date)

        while cond:
            try:
                t = t.replace(day=t.day+1, hour=0,minute=0,second=0) 
            except:
                ok = False
                break

            if strict:
                cond = (day != -1 and t.weekday()+1 != day) or (date != -1 and t.day != date)
            else:
                cond = (day != -1 and t.weekday()+1 != day) and (date != -1 and t.day != date)

        if not ok:
            try:
                t = t.replace(month=t.month+1, day=1, hour=0,minute=0,second=0) 
            except:
                t = t.replace(year=t.year+1, month=1,day=1, hour=0,minute=0,second=0)
            continue

        while (hour != -1 and hour != t.hour):
            try:
                t = t.replace(hour=t.hour+1,minute=0,second=0) 
            except:
                ok = False
                break

        if not ok:
            t = t.replace(hour=0,minute=0,second=0)
            t += dt.timedelta(days=1)
            continue

        while (minute != -1 and minute != t.minute):
            try:
                t = t.replace(minute=t.minute+1,second=0) 
            except:
                ok = False
                break

        if not ok:
            t = t.replace(minute=0,second=0)
            t += dt.timedelta(seconds=60*60)
            continue

        while (second != -1 and second != t.second):
            try:
                t = t.replace(second=t.second+1) 
            except:
                ok = False
                break

        if not ok:
            t = t.replace(second=0)
            t += dt.timedelta(seconds=60)
            continue

        delt = (t-epoch)
        #print t
        print safe + delt.days*60*60*24 + delt.seconds
        break