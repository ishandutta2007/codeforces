import subprocess
import time
import random

MIN_WAIT_SEC = 1000
MAX_WAIT_SEC = 3000
MAX_FILES_TO_ADD = 900


def compact(lst):
    return list(filter(None, lst))


for i in range(1, 900):
    print("[{}]Initializing git status1".format(i))
    p = subprocess.Popen(["git", "status"], stdout=subprocess.PIPE)
    out, err = p.communicate()
    outlist1 = out.decode("utf-8").split("\n")
    print(outlist1)
    trimmed = False
    for idx, elem in enumerate(outlist1):
        if "Untracked files" in elem:
            outlist1 = outlist1[idx + 2 :]
            outlist1 = compact(outlist1)
            outlist1 = outlist1[:-1]
            outlist1 = outlist1[:MAX_FILES_TO_ADD]
            trimmed = True
            break
    if trimmed == False:
        outlist1 = []
    print("[{}]outlist1 filterd by untracked".format(i))
    print(outlist1)
    print("[{}]Done git status1".format(i))
    print("=====")

    print("[{}]Initializing git add".format(i))
    for idx, elem in enumerate(outlist1):
        try:
            elem = elem.strip()
            # if ".cpp" in elem or ".c" in elem or ".py" in elem:
            print("[{}][{}]Running git add {}".format(i, idx, elem))
            p = subprocess.Popen(["git", "add", elem], stdout=subprocess.PIPE)
            out, err = p.communicate()
            print(out.decode("utf-8").split("\n"))
        except:
            pass
    print("[{}]Done git add".format(i))
    print("=====")

    print("[{}]Initializing git status2".format(i))
    p = subprocess.Popen(["git", "status"], stdout=subprocess.PIPE)
    out, err = p.communicate()
    outlist = out.decode("utf-8").split("\n")
    print(outlist)

    finalfilelist = []
    for elem in outlist:
        if "\tnew file:" in elem:
            finalfilelist.append(elem)

    print(finalfilelist)

    finalfolderlist = []
    for elem in finalfilelist:
        try:
            finalfolderlist.append(
                elem.replace("\tnew file:", "").strip().split("/")[0]
            )
        except Exception as e:
            pass

    print(finalfolderlist)
    if len(finalfolderlist) == 0:
        r = random.randint(MIN_WAIT_SEC, MAX_WAIT_SEC)
        print("[{}]Waiting {} secs....".format(i, r))
        time.sleep(r)
        continue
    freq = {x: finalfolderlist.count(x) for x in finalfolderlist}
    print(freq)
    max_key = max(freq, key=freq.get)

    print(max_key)
    try:
        elem = max_key.strip()
        print("[{}][{}]Running git add {}/downloaded".format(i, idx, elem))
        p = subprocess.Popen(
            ["git", "add", elem + "/downloaded"], stdout=subprocess.PIPE
        )
        out, err = p.communicate()
        print(out.decode("utf-8").split("\n"))

        print("[{}][{}]Running git add {}/errors".format(i, idx, elem))
        p = subprocess.Popen(["git", "add", elem + "/errors"], stdout=subprocess.PIPE)
        out, err = p.communicate()
        print(out.decode("utf-8").split("\n"))
    except:
        pass

    print("[{}]Done git status2".format(i))
    print("=====")

    print("[{}]Initializing git commit".format(i))
    p = subprocess.Popen(["git", "commit", "-m", max_key], stdout=subprocess.PIPE)
    out, err = p.communicate()
    print(out.decode("utf-8").split("\n"))
    print("[{}]Done git commit".format(i))
    print("=====")

    if i % 5 == 0 or i % 7 == 0:
        print("[{}]Initializing git push".format(i))
        p = subprocess.Popen(["git", "push"], stdout=subprocess.PIPE)
        out, err = p.communicate()
        print(out.decode("utf-8").split("\n"))
        print("[{}]Done git push".format(i))
        print("=====")
